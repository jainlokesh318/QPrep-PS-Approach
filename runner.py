
import argparse
import os
import sys
import git
from git import Repo

TIMEOUT_FOR_ONE_JAVA_TESTCASE = 5.0

import subprocess

def remove_whitespace(file_x):
    f = open(file_x, 'r+')
    lines = f.readlines()
    f.close()

    lines = list(filter(lambda x: x.strip() != '', lines))
    lines = list(map(lambda x: x.strip(), lines))
    return lines

def filecompare_ignore_whitespace(file1, file2):
    c1 = remove_whitespace(file1)
    c2 = remove_whitespace(file2)

    return c1 == c2

def run_command_with_timeout(cmd, timeout_in_seconds):
    ret = subprocess.call(cmd, shell=True, timeout=timeout_in_seconds)
    return ret
def run(name_of_the_problem, language='c++'):

    assert language in ['java', 'c++', 'c++11', 'c++14', 'c++17', 'python']

    full_path = os.path.join(os.getenv('PWD'), name_of_the_problem, 'tests')

    all_test_files = os.listdir(full_path)
    compile_cmd = {
            'java' : 'cd ' + name_of_the_problem + ' && javac -cp ../crio/java ' + '*.java',
            'c++'  : 'cd ' + name_of_the_problem + ' && g++  -std=c++03 ' + name_of_the_problem + '.cpp -o ' + name_of_the_problem + '.out',
            'c++11'  : 'cd ' + name_of_the_problem + ' && g++ -std=c++11 ' + name_of_the_problem + '.cpp -o ' + name_of_the_problem + '.out',
            'c++14'  : 'cd ' + name_of_the_problem + ' && g++ -std=c++14 ' + name_of_the_problem + '.cpp -o ' + name_of_the_problem + '.out',
            'c++17'  : 'cd ' + name_of_the_problem + ' && g++ -std=c++17 ' + name_of_the_problem + '.cpp -o ' + name_of_the_problem + '.out',
            #'python' : 'cd ' + name_of_the_problem + ' && pylint --disable=missing-docstring ' + name_of_the_problem + '.py'
            }

    compile_program = 'exit 0'
    if language in compile_cmd:
        compile_program = compile_cmd[language]

    evaluate_file = name_of_the_problem + '/evaluate.py'
    multiple_solution_possible = os.path.exists(evaluate_file)

    if multiple_solution_possible:
        print('\n====== Multiple solutions =========\n')

    ret = os.system(compile_program)

    if ret != 0 and language not in ['python']:
        return test_results

    test_results = {}

    for file_name in sorted(all_test_files):
        if 'input-' in file_name:
            output_file_name = file_name.replace('input-', 'output-')
            test_name = file_name.replace('input-', 'test-')

            if output_file_name in sorted(all_test_files):
                test_output_filename = 'actual-{}'.format(output_file_name)
                try:
                    run_one_test(language, name_of_the_problem, file_name, test_output_filename)
                    passed = False
                    if multiple_solution_possible:
                        cmd = 'python3 {} {} {} {}'.format(evaluate_file, name_of_the_problem + '/tests/' + file_name, name_of_the_problem + '/tests/' + output_file_name, name_of_the_problem + '/' + test_output_filename)
                        proc = subprocess.run(cmd, shell=True)
                        passed = proc.returncode == 0
                    else:
                        passed = filecompare_ignore_whitespace(os.path.join(name_of_the_problem, test_output_filename), '{}/tests/{}'.format(name_of_the_problem, output_file_name))

                    if passed:
                        print('%-25s : Passed' % (file_name))
                        test_results[test_name] = 'PASSED'
                    else:
                        print('%-25s : Failed' % (file_name))
                        test_results[test_name] = 'FAILED'
                        all_tests_passed = False
                except:
                    test_results[test_name] = 'TIMEDOUT'
                    all_tests_passed = False
                    print('%-25s: Timedout' % (file_name))


def run_one_test(language, name_of_the_problem, input_file_name, output_file_name):
    run_cmd = {
            'java' : 'java -cp .:../crio/java ' + name_of_the_problem,
            'c++' :  './' + name_of_the_problem  + '.out',
            'c++11' : './' + name_of_the_problem  + '.out',
            'c++14' :  './' + name_of_the_problem  + '.out',
            'c++17' :  './' + name_of_the_problem  + '.out',
            'python' : 'export PYTHONPATH=../crio/python && python3 ' + name_of_the_problem  + '.py',
            }

    cmd = "{} < tests/{} > {}".format(run_cmd[language], input_file_name, output_file_name)
    full_cmd = "cd {} && {}".format(name_of_the_problem, cmd)
    try:
        run_command_with_timeout(full_cmd, TIMEOUT_FOR_ONE_JAVA_TESTCASE)
    except:
        #e = sys.exc_info()[0]
        #print(e)
        print('Timedout')


def run_with_custom_input(name_of_the_problem, language, input_file_path):
    assert language in ['java', 'c++', 'c++11', 'c++14', 'c++17', 'python']
    if input_file_path:
        input_file_path = os.path.abspath(input_file_path)
    compile_cmd = {
            'java' : 'cd ' + name_of_the_problem + ' && javac -cp ../crio/java ' + '*.java',
            'c++'  : 'cd ' + name_of_the_problem + ' && g++  -std=c++03 ' + name_of_the_problem + '.cpp -o ' + name_of_the_problem + '.out',
            'c++11'  : 'cd ' + name_of_the_problem + ' && g++ -std=c++11 ' + name_of_the_problem + '.cpp -o ' + name_of_the_problem + '.out',
            'c++14'  : 'cd ' + name_of_the_problem + ' && g++ -std=c++14 ' + name_of_the_problem + '.cpp -o ' + name_of_the_problem + '.out',
            'c++17'  : 'cd ' + name_of_the_problem + ' && g++ -std=c++17 ' + name_of_the_problem + '.cpp -o ' + name_of_the_problem + '.out',
            'python' : 'cd ' + name_of_the_problem + ' && export PYTHONPATH=../crio/python && python -m py_compile ' + name_of_the_problem + '.py'
            }
    compile_program = compile_cmd[language]

    ret = os.system(compile_program)

    if ret != 0 and language not in ['python']:
        return False


    run_cmd = {
        'java' : 'cd ' + name_of_the_problem + ' &&  java -cp .:../crio/java ' + name_of_the_problem,
        'c++' :  'cd ' + name_of_the_problem + ' &&  ./' + name_of_the_problem  + '.out',
        'c++11' :  'cd ' + name_of_the_problem + ' &&  ./' + name_of_the_problem  + '.out',
        'c++14' :  'cd ' + name_of_the_problem + ' &&  ./' + name_of_the_problem  + '.out',
        'c++17' :  'cd ' + name_of_the_problem + ' &&  ./' + name_of_the_problem  + '.out',
        'python' : 'cd ' + name_of_the_problem + ' &&  export PYTHONPATH=../crio/python && python3  ' + name_of_the_problem  + '.py'
    }

    cmd2 = run_cmd[language]
    TIMEOUT_FOR_CUSTOM_INPUT = TIMEOUT_FOR_ONE_JAVA_TESTCASE * 100
    if input_file_path:
        TIMEOUT_FOR_CUSTOM_INPUT //= 100
        cmd2 += ' < ' + input_file_path
    try:
        run_command_with_timeout(cmd2, TIMEOUT_FOR_CUSTOM_INPUT)
    except:
        print('Timedout')
    return True

def commit_msg(name_of_the_problem, submission_type, language):
    return "[{}]:[{}]:[{}]".format(submission_type, name_of_the_problem, language)

 
def local_run(name_of_the_problem, type_of_run, lang):
    repo = Repo(os.getenv('PWD'))
    repo.index.add([name_of_the_problem], force=False)
    repo.index.commit(commit_msg(name_of_the_problem, type_of_run, lang))
def submit(name_of_the_problem):
    repo = Repo('.')
    repo.index.add([name_of_the_problem], force=False)

def submit(name_of_the_problem, lang):
    repo = Repo(os.getenv('PWD'))
    repo.index.add([name_of_the_problem], force=False)
    repo.index.commit(commit_msg(name_of_the_problem, "Solved", lang))
    repo.remotes.origin.push()

def get_submission_type_and_problem_id():
    repo = Repo(os.getenv('PWD'))
    commits = list(repo.iter_commits('master', max_count=5))

    commit = commits[0]
    print(commit.message)
    lst = [x.strip('[]') for x in commit.message.split(":")]
    print(lst)
    submission = lst[0]
    problem_id = lst[1]
    return (submission, problem_id)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(prog='myprogram')
    parser.add_argument('-r', '--run', help='Run problem id', action='store_true')
    parser.add_argument('-s', '--submit', help='Submit problem id', action='store_true')
    parser.add_argument('-t', '--test-all', help='all assessment for all problems', action='store_true')
    parser.add_argument('-l', '--lang', help='solution language')
    parser.add_argument('-p', '--problem', help='name of the problem solved')
    parser.add_argument('--dev' , help='dev mode', action='store_true')
    parser.add_argument('--test' , help='test problem with custom input file', action='store_true')
    parser.add_argument('--input' , help='input file for custom input')

    args = parser.parse_args()

    if not os.path.exists('crio'):
        os.system('mkdir crio')
        os.system('git clone https://gitlab.crio.do/crio_libs/crio_ps_ds.git crio')
    else:
        ret = os.system('cd crio && git pull')
        if ret != 0:
            os.system('rm -rf crio/* && git clone https://gitlab.crio.do/crio_libs/crio_ps_ds.git crio')
  
    
    if args.test_all:
        all_problems = [dir for dir in os.listdir(os.getenv('PWD')) if dir[0] >= 'A' and dir[0] <= 'Z']
        all_passed = True
        for problem in all_problems:
            res = run(problem)
            all_passed = all_passed and res
            print(problem, ['FAILED','PASSED'][res])

        if all_passed:
            sys.exit(0)
        else:
            sys.exit(1)

    dirs = os.listdir('.')
    if not args.problem in dirs:
        # print(dirs)
        print('Error: Invalid problem id: ', args.problem)
        sys.exit(1)

    if args.run:
        run(args.problem, args.lang)
        if not args.dev:
            local_run(args.problem, "LocalTest", args.lang)

    if args.test:
        if args.input:
            if not os.path.exists(args.input):
                print("Make sure file exists")
                sys.exit(1)
        run_with_custom_input(args.problem, args.lang, args.input)

        if not args.dev:
            local_run(args.problem, "SingleTest", args.lang)

    if args.submit:
        run(args.problem, args.lang)
        if not args.dev:
            submit(args.problem, args.lang)
            get_submission_type_and_problem_id()
