{\rtf1\ansi\ansicpg1252\cocoartf2513
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\paperw11900\paperh16840\margl1440\margr1440\vieww10800\viewh8400\viewkind0
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural\partightenfactor0

\f0\fs24 \cf0 class Solution:\
    def sequentialDigits(self, low: int, high: int) -> List[int]:\
        res = []\
        for i in range(1, 10):\
            res.extend(all_nums_starting_with(i))\
        res = [r for r in res if low <= r <= high]\
        res.sort()\
        return res\
        \
def all_nums_starting_with(n):\
    num = n\
    res = [n]\
    for i in range(n + 1, 10):\
        n = n * 10 + i\
        res.append(n)\
    return res\
}