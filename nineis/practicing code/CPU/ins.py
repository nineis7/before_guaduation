import os
# from posixpath import dirname

dirname = os.path.dirname(__file__)
filename = os.path.join(dirname, 'ins.bin')


# 我们所要做的是确定每一个位的含义 每次计算出一个十六位数值（即指令），将该数值传给ROM中
# 而该ROM便作为我们的内存存放指令

WE_A = 2 ** 0 # 1 有效
CS_A = 2 ** 1 # 1x enable

WE_B = 2 ** 2
CS_B = 2 ** 3

WE_C = 2 ** 4
CS_C = 2 ** 5

ALU_ADD = 0 # ALU 默认为加法
ALU_SUB = 2 ** 6
ALU_OUT = 2 ** 7

WE_M = 2 ** 8
CS_M = 2 ** 9

WE_PC = 2 ** 10
EN_PC = 2 ** 11
CS_PC = 2 ** 12

HLT= 2 ** 15

micro = [
    CS_M | CS_A | WE_A | WE_PC | EN_PC | CS_PC,
    CS_M | CS_B | WE_B | WE_PC | EN_PC | CS_PC,
    CS_C | WE_C | ALU_OUT | ALU_SUB, 
    CS_C | CS_M | WE_M, # CS_C 表示把C寄存器中的值输入到总线中
    HLT,
]

with open(filename, 'wb') as file:
    for value in micro:
        result = value.to_bytes(2, byteorder='little')
        file.write(result)
        print(value, result)

print('Finish compile!!!')