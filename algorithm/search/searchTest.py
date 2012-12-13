#!/usr/bin/env python2

import os
import subprocess
import unittest
import random

class searchTest(unittest.TestCase):
    __test__ = False
    dictFile = r'cracklib-small'

    def runCmd(self, command):
        self.p = subprocess.Popen(command, cwd=os.getcwd(), shell=True)
        return self.p.wait()

    def generateFile(self, name, size):
        dict = open(self.dictFile, 'r').read().splitlines()
        with open(name, 'w') as f:
            for i in range(size):
                line = "%09d\t%s\t%d\n" % (i, ' '.join(random.sample(dict, random.randint(1, 30))), random.randint(1, 10000))
                f.write(line)

    def generateInput(self, name, size):
        dict = open(self.dictFile, 'r').read().splitlines()
        with open(name, 'w') as f:
            for i in range(size):
                f.write('%s\n' % ' '.join(random.sample(dict, random.randint(1, 3))))

class TestDefaultData(searchTest):
    __test__ = True

    def setUp(self):
        pass

    def testDefault(self):
        print self.runCmd(r"cat queries.txt | ./lookup")

class TestBigData(searchTest):
    __test__ = True

    def setUp(self):
        self.generateFile(r"temp.corpus", 100*1000)
        self.generateInput(r"input.txt", 50)

    def testDefault(self):
        print self.runCmd(r"cat input.txt | ./lookup inverted temp.corpus")

class TestSmallData(searchTest):
    __test__ = True

    def setUp(self):
        self.generateFile(r"temp2.corpus", 1000)
        self.generateInput(r"input2.txt", 50)

    def testDefault(self):
        print self.runCmd(r"cat input2.txt | ./lookup inverted temp2.corpus")

if __name__ == '__main__':
    unittest.main()