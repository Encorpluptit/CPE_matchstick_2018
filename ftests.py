#!/usr/bin/env python3
##
## EPITECH PROJECT, 2019
## Any project.
## File description:
## Functionnals tests for projects.
##

################################################################################
#=============#
# == TO DO == #
#=============#
# make main with a list type of args, and transform test_** functions
#     in "for i in range list: test(argv[i]") (maybe keep main with all tests)
# simple_launch :  rewrite tests function?? (principal function that work with a
#     flag or differents functions with test name like "stdout_exit")
# Launch pgrm + ref -> "simple launch" heritage ?
# rename class (ex: launch -> run)
# faire un check des banned functions grep -rnw "printf(\|my_strdup(\LIB"
################################################################################





################################################################################
#===============#
# == IMPORTS == #
#===============#
from subprocess import Popen, PIPE
################################################################################





################################################################################
#=======================#
# ==  PROGRAMS NAMES == #
#=======================#
PGRM = "./104inter"
REFPGRM = "./104intersection"

# SAVES
#REFPGRM = PGRM + "_ref"
#REFPGRM = "./104intersection"
#REFPRGM = "tcsh"


################################################################################





################################################################################
#=============================#
# ==  PRINT ERRORS STRINGS == #
#=============================#
ASSERT_STDOUT_ERR = "Assertion error: stdout."
ASSERT_STDERR_ERR = "Assertion error: stderr."
ASSERT_EXIT_ERR = "Assertion error: exit code."

ARGUMENTS = "Arguments: {}"

PGRM_STDOUT_ERR = "PROGRAM STDOUT:\n{}"
REF_STDOUT_ERR = "REFERENCE STDOUT:\n{}"

PGRM_STDERR_ERR = "PROGRAM STDERR:\n{}"
REF_STDERR_ERR = "REFERENCE STDERR:\n{}"

PGRM_EXIT_ERR = "PROGRAM EXIT CODE:\n{}"
REF_EXIT_ERR = "REFERENCE EXIT CODE:\n{}"

TEST_END = "End of the test\n<===========================================>\n\n"

TEST_PRINT = "{:-^50}"
TEST_DESCRIPTION = " TEST NUMBER {} "

TEST_NUMBER  = 0
################################################################################





################################################################################
#=============================#
# ==  SIMPLE LAUNCH CLASS  == #
#=============================#
class launch_simple:
    def __init__(self, cmd):
        self.command = str.encode(cmd)
        self.my_pgrm = Popen([PGRM], stdin=PIPE, stdout=PIPE, stderr=PIPE, shell=True)
        self.pgrm_stdout, self.pgrm_stderr = self.my_pgrm.communicate(input = self.command)
        self.pgrm_returncode = self.my_pgrm.returncode

    # def test(self):
    #     global TEST_NUMBER
    #     TEST_NUMBER += 1
    #     try:
    #         assert(self.pgrm_stdout == self.ref_stdout)
    #     except AssertionError:
    #         print(TEST_PRINT.format(TEST_DESCRIPTION.format(TEST_NUMBER)))
    #         print(ASSERT_STDOUT_ERR)
    #         print(ARGUMENTS.format(self.arguments))
    #         print(PGRM_STDOUT_ERR.format((self.pgrm_stdout).decode("utf-8")))
    #         print(REF_STDOUT_ERR.format((self.ref_stdout).decode("utf-8")))
    #         print(TEST_END)

    #     try:
    #         assert(self.pgrm_stderr == self.ref_stderr)
    #     except AssertionError:
    #         print(TEST_PRINT.format(TEST_DESCRIPTION.format(TEST_NUMBER)))
    #         print(ASSERT_STDERR_ERR)
    #         print(PGRM_STDERR_ERR.format((self.pgrm_stderr).decode("utf-8")))
    #         print(REF_STDERR_ERR.format((self.ref_stderr).decode("utf-8")))
    #         print(TEST_END)

    #     try:
    #         assert(self.pgrm_returncode == self.ref_returncode)
    #     except AssertionError:
    #         print(TEST_PRINT.format(TEST_DESCRIPTION.format(TEST_NUMBER)))
    #         print(ASSERT_EXIT_ERR)
    #         print(PGRM_EXIT_ERR.format(self.pgrm_returncode))
    #         print(REF_EXIT_ERR.format(self.ref_returncode))
    #         print(TEST_END)

    def test_stdout(self, stdout):
        assert(self.pgrm_stdout == stdout)

    def test_stderr(self, stderr):
        assert(self.pgrm_stderr == stderr)

    def test_returncode(self, returncode):
        assert(self.pgrm_returncode == returncode)

################################################################################





################################################################################
#==========================#
# ==  REF LAUNCH CLASS  == #
#==========================#
class launch_both:
    def __init__(self, cmd):
        command = PGRM + " " + cmd
        self.command = str.encode(command)
        command = REFPGRM + " " + cmd
        self.arguments = cmd
        self.ref_command = str.encode(command)
        self.my_pgrm = Popen(["bash"], stdin=PIPE, stdout=PIPE, stderr=PIPE, shell=True)
        self.ref_pgrm = Popen(["bash"], stdin=PIPE, stdout=PIPE, stderr=PIPE, shell=True)
        self.pgrm_stdout, self.pgrm_stderr = self.my_pgrm.communicate(input = self.command)
        self.ref_stdout, self.ref_stderr = self.ref_pgrm.communicate(input = self.ref_command)
        self.pgrm_returncode = self.my_pgrm.returncode
        self.ref_returncode = self.ref_pgrm.returncode

    def test(self):
        global TEST_NUMBER
        TEST_NUMBER += 1
        try:
            assert(self.pgrm_stdout == self.ref_stdout)
        except AssertionError:
            print(TEST_PRINT.format(TEST_DESCRIPTION.format(TEST_NUMBER)))
            print(ASSERT_STDOUT_ERR)
            print(ARGUMENTS.format(self.arguments))
            print(PGRM_STDOUT_ERR.format((self.pgrm_stdout).decode("utf-8")))
            print(REF_STDOUT_ERR.format((self.ref_stdout).decode("utf-8")))
            print(TEST_END)

        try:
            assert(self.pgrm_stderr == self.ref_stderr)
        except AssertionError:
            print(TEST_PRINT.format(TEST_DESCRIPTION.format(TEST_NUMBER)))
            print(ASSERT_STDERR_ERR)
            print(PGRM_STDERR_ERR.format((self.pgrm_stderr).decode("utf-8")))
            print(REF_STDERR_ERR.format((self.ref_stderr).decode("utf-8")))
            print(TEST_END)

        try:
            assert(self.pgrm_returncode == self.ref_returncode)
        except AssertionError:
            print(TEST_PRINT.format(TEST_DESCRIPTION.format(TEST_NUMBER)))
            print(ASSERT_EXIT_ERR)
            print(PGRM_EXIT_ERR.format(self.pgrm_returncode))
            print(REF_EXIT_ERR.format(self.ref_returncode))
            print(TEST_END)


    def test_stdout(self):
        assert(self.pgrm_stdout == self.ref_stdout)

    def test_stderr(self):
        assert(self.pgrm_stderr == self.ref_stderr)

    def test_returncode(self):
        assert(self.pgrm_returncode == self.ref_returncode)

# def test_ls():
#     ls = simpleTest("ls")
#     ls.test()

def test_both(arg):
    test = launch_both(arg)
#    test.OER

def test_01():
    test_01 = launch_both("1 4 0 3 0 0 -2 4")
    test_01.test()
def test_02():
    test_02 = launch_both("1 5 4 8 9 6 4 5 ")
    test_02.test()
def test_03():
    test_03 = launch_both("2 5 4 8 9 6 4 5")
    test_03.test()
def test_04():
    test_04 = launch_both("2 1 0 0 0 0 1 1")
    test_04.test()
def test_05():
    test_05 = launch_both("1 0 0 2 1 1 0 1")
    test_05.test()
def test_06():
    test_06 = launch_both("1 4 0 3 0 0 -2 4")
    test_06.test()
def test_07():
    test_07 = launch_both("2 0 0 2 1 1 0 1")
    test_07.test()
def test_08():
    test_08 = launch_both("3 -1 -1 -1 1 1 5 30")
    test_08.test()
def test_10():
    test_10 = launch_both("2 1 0 0 0 0 1 1")
    test_10.test()
def test_11():
    test_11 = launch_both("2 1 0 0 0 0 1 1")
    test_11.test()
def test_12():
    test_12 = launch_both("2 1 0 0 0 0 1 1")
    test_12.test()
def test_13():
    test_13 = launch_both("2 1 0 0 0 0 1 1")
    test_03.test()
def test_14():
    test_14 = launch_both("2 1 0 0 0 0 1 1")
    test_14.test()
def test_15():
    test_15 = launch_both("2 1 0 0 0 0 1 1")
    test_15.test()
def test_16():
    test_16 = launch_both("2 1 0 0 0 0 1 1")
    test_16.test()
def test_17():
    test_17 = launch_both("2 1 0 0 0 0 1 1")
    test_17.test()
def test_18():
    test_18 = launch_both("2 1 0 0 0 0 1 1")
    test_18.test()
def test_19():
    test_19 = launch_both("2 1 0 0 0 0 1 1")
    test_19.test()


def main():
    try:
        test_01()
        test_02()
        test_03()
        test_04()
        test_05()
        test_06()
        test_07()
        test_08()
        test_09()
        test_10()
        test_11()
        test_12()
        test_13()
        test_14()
        test_15()
        test_16()
        test_17()
        test_18()
        test_19()
    except NameError:
        pass

if __name__ == "__main__":
    main()

################################################################################





################################################################################
#=============#
# == SAVES == #
#=============#
# def main():
#     test_01()
#     test_02()
#     test_03()
#     test_04()
#     test_05()
#     test_06()
#     test_07()
#     test_08()
#     test_09()
#     test_10()
#     test_11()
#     test_12()
#     test_13()
#     test_14()
#     test_15()
#     test_16()
#     test_17()
#     test_18()
#     test_19()
