#-*- utf-8 -*-
import math

# Test whether the random positive number K can be adequate
# for mostly usage. The test range is from 1 to 10 billion.

# The following functions are the congruence equation solutions
#  that we used in a designed algorithm.

# The general solution formula of x^2=-1(mod p)
# Formula: p = 4*k + 1
def SolutionFormula1(k):
    return 4*k+1

# The general solution formula of x^2=2(mod p)
# Formula: p = 8*k + 1 & p = 8*k + 7
def SolutionFormula2(k):
    return 8*k+1

def SolutionFormula3(k):
    return 8*k+7

# The general solution formula of x^2=-2(mod p)
# Formula: p = 8*k + 1 & p = 8*k + 3
def SolutionFormula4(k):
    return 8*k+1

def SolutionFormula5(k):
    return 8*k+3

# The general solution formula of x^2=3(mod p)
# Formula: p = 12*k + 1 & p = 12*k + 11
def SolutionFormula6(k):
    return 12*k+1

def SolutionFormula7(k):
    return 12*k+11

# The general solution formula of x^2=-3(mod p)
# Formula: p = 6*k + 1
def SolutionFormula8(k):
    return 6*k+1

def IsPrime(n):
    border = int(math.sqrt(n))
    if 1==n:
        return 0
    elif (2==n or 3==n):
        return 1
    elif (n%6 != 1 and n%6 != 5):
        return 0
    else:
        for index in range(5, border+1, 6):
            if (n%index == 0) or (n%(index+2) == 0):
                return 0
        return 1

def LegendreFormula(d,p):
    if 1==d:
        return 1
    elif 0 == d%p:
        return 0
    elif -1 == d:
        if (((p-1)/2)%2):
            return -1
        else:
            return 1
    elif 0 == d%2:
        return -1*LegendreFormula(d/2, p) if ((p*p-1)/8)%2 else LegendreFormula(d/2, p)
    else:
        return -1*LegendreFormula(p%d, d) if ((d-1)*(p-1)/4)%2 else LegendreFormula(p%d, d)

def calcLeftCmpEle(seq=None):
    summary = 0
    for index in range(0, len(seq), 2):
        summary += seq[index]
    return summary

def calcRightCmpEle(seq=None, zero_one_lt=None):
    summary = 0
    for index in range(len(seq)):
        summary += int(seq[index])*int(zero_one_lt[index])
    return summary

def genZeroOneList(DList, P, Res=None):
    PresetTable = [[0, 0], [0, 1], [1, 0]]
    for d in DList:
        Res.extend(PresetTable[LegendreFormula(d, P)+1])


if __name__ == '__main__':
    seqB = [3, 5, 9, 25, 57, 121, 249, 505, 1017, 2041]
    d_list = [-1, 2, -1, 3, -3]
    C = calcLeftCmpEle(seqB)
    D = 0
    solutions = [SolutionFormula1,\
                 SolutionFormula2,\
                 SolutionFormula3,\
                 SolutionFormula4,\
                 SolutionFormula5,\
                 SolutionFormula6,\
                 SolutionFormula7,\
                 SolutionFormula8]
    ans = []
    tmp = []
    zero_one_list = []
    abnormal_list = []

    for k in range(1, 1000000000000, 1):
        print("The current K value is: %d" % k)
        tmp.clear()
        # a k value may generate several prime p
        # To get an accurate test result, I decide to submit each
        # of the prime p in the same group into the LegendreFormula
        # then
        for formula in solutions:
            p = formula(k)
            if IsPrime(p):
                tmp.append(k)
                tmp.append(p)
                # Generate the 0-1 integer list
                genZeroOneList(d_list, p, zero_one_list)
                D = calcRightCmpEle(seqB, zero_one_list)
                # print("C value is:%d" % C)
                # print("D value is: %d" % D)
                tmp.append(zero_one_list)
                if D>=C:
                    print("Find a TRUE situation!")
                    print(tmp)
                    abnormal_list.append(tmp)
                zero_one_list.clear()
            ans.append(tmp)

    if len(abnormal_list) == 0:
        print("Congratulations! This is a perpetual false predicate generator.")
    else:
        print("We find some abnormal K values which can make C>D true. See the following list:")
        for ele in abnormal_list:
            print(ele)
