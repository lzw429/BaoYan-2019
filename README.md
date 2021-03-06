# 保研机试

## 开发与测评环境

尽可能模拟机试的开发与测评环境，本仓库中的所有 C++ 代码采用 C++98.

以下是 [百练 OJ](http://openjudge.cn/help.html) 的语言要求。

| Language | Compiler(s)                                                  | Standard           | Remark(s)                                                    |
| -------- | ------------------------------------------------------------ | ------------------ | ------------------------------------------------------------ |
| C        | MS VC++ 2008 Express (“`C`”) and MinGW GCC 4.4.0 (“`GCC`”)   | C99                | The macro `ONLINE_JUDGE` is defined.The C99 implementation of GCC 4.4.0 is not considered feature-complete. In particular, support for variable-length arrays and intrinsic complex and imaginary types is labeled “broken”. |
| C++      | MS VC++ 2008 Express (“`C++`”) and MinGW GCC 4.4.0 (“`G++`”) | C++98              | The macro `ONLINE_JUDGE` is defined.Currently there is no plan to enable the experimental C++0x features before the new C++ standard is officially published and relatively well-supported. |
| Java     | JDK 6 (“`Java`”)                                             |                    | The system property `ONLINE_JUDGE` is s.You should write a class named `Main` with public or package visibility. This `Main` class should contain the entry-point `main` method. |
| Pascal   | FreePascal 2.2.0 (“`Pascal`”)                                | FreePascal dialect | The macro `ONLINE_JUDGE` is defined.                         |
| Fortran  | MinGW GCC 4.4.0 (“`Fortran`”)                                | Fortran 95         |                                                              |


## 仓库公开

作者保留所有权利。
