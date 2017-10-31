[Sysprog2017] HW4 2017-81842
===

==< Gao Zhiyuan >==

Q1
---

#### To build all targets

```
$make all
```
#### To clean up

```
$make clean
```

#### Ideal output will be

```
$make all
$./foo
This is foo dep 1
This is foo dep 2
$./bar
This is bar dep 1
This is bar dep 2
$
```

Q2
---

```
   Num:    Value          Size Type    Bind   Vis      Ndx Name
     9: 0000000000000000     0 SECTION LOCAL  DEFAULT    6 
    10: 0000000000000000     4 OBJECT  GLOBAL DEFAULT    3 strong
    11: 0000000000000004     4 OBJECT  GLOBAL DEFAULT  COM weak
    12: 0000000000000000     7 FUNC    GLOBAL DEFAULT    1 foo
    13: 0000000000000007    39 FUNC    GLOBAL DEFAULT    1 main
    14: 0000000000000000     0 NOTYPE  GLOBAL DEFAULT  UND ext_var
    15: 0000000000000000     0 NOTYPE  GLOBAL DEFAULT  UND printf

```

	variable strong is a gloabl string variable in main.c. 
Variable weak is a weak symbol, which could be inferred from COM Ndx. 
While ext_var is a extern variable defined in ext_file.c but referenced in main.c. We could tell by its UND Ndx, which means undefined symbols. 

I defined a static local variable but it doesn't show up here. I really don't know why. 

Q3
---

Library is composed from one.c, two.c, three.c. 

#### To generate library file

```
$make lib
```

#### To compile main C file

```
$make main
```

#### Make a archieve in Makefile

```
ar rcs mylib.a one.o two.o three.o
```
