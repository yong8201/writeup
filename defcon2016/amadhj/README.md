dev@9700cc6726c1:/work$ clang -emit-llvm -g -o amadhj_hexray.ll -c amadhj_hexray.c
amadhj_hexray.c:23:179: warning: '&' within '|' [-Wbitwise-op-parentheses]
          return ((unsigned __int64)(unsigned __int8)(a1 >> 8 * a2) << 8 * a3) | ((unsigned __int64)(unsigned __int8)(a1 >> 8 * a3) << 8 * a2) | ~(255LL << 8 * a2) & ~(255LL << 8 * a3) & a1;
                                                                                                                                               ~ ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~
amadhj_hexray.c:23:179: note: place parentheses around the '&' expression to silence this warning
          return ((unsigned __int64)(unsigned __int8)(a1 >> 8 * a2) << 8 * a3) | ((unsigned __int64)(unsigned __int8)(a1 >> 8 * a3) << 8 * a2) | ~(255LL << 8 * a2) & ~(255LL << 8 * a3) & a1;
                                                                                                                                                                                         ^
                                                                                                                                                 (                                           )
1 warning generated.
dev@9700cc6726c1:/work$ klee amadhj_hexray.ll
KLEE: output directory is "/work/klee-out-14"
KLEE: ERROR: /work/amadhj_hexray.c:524: ASSERTION FAIL: 0
KLEE: NOTE: now ignoring this error at this location

KLEE: done: total instructions = 71697
KLEE: done: completed paths = 2
KLEE: done: generated tests = 2
dev@9700cc6726c1:/work$ ls klee-last
assembly.ll  info  messages.txt  run.istats  run.stats  test000001.ktest  test000002.assert.err  test000002.ktest  test000002.pc  warnings.txt
dev@9700cc6726c1:/work$ ktest-tool --write-ints klee-last/test000002.ktest
ktest file : 'klee-last/test000002.ktest'
args       : ['amadhj_hexray.ll']
num objects: 1
object    0: name: 'key'
object    0: size: 32
object    0: data: 'TyL LKT vfOpWmxMTAMl_ZfVnZYmqhuQ'
dev@9700cc6726c1:/work$
