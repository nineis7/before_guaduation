侯捷C++ 笔记

- state member function can only reach static data members for it has no this pointer.

- object oriented programming
  
  - composition
    - ctor: constructor from within
    - dtor: deconstructor from outside
  - delegation aka. composition by reference 
  - inheritance                                                                                                                                                                                                         

- inheritance with virtual functions
  
  - non-virtual functions: you don't want derived class to override them.
  - virtual functions (impure virtual functions): you hope derived classes to override them.
  - pure virtual functions: you force derived classes to override them. cause you don't have default definitions. virtual XXX *=0*

- when providing default parameter values, we can just input one argument, leaving another one being assignment by default. Through this way can we satisfy our needs to choose to append second parameter according to our needs.

- 函数的返回值
  
  - 返回值为bool，将所需改变的变量当作参数传引用(call by reference)，可以通过返回值显示状态（true or false）
  
  - 返回值类型为reference时，不能传function scope的变量，必须是引用进来的变量。
  
  - 返回类型为pointer，可以在function中创建静态变量，将其地址返回。在外面用该类型指针接住：
    
    - `const vector<int>* vec_ptr = createVec(size);`  从而不需要用户提前创建vector将其作为参数传入。
    
    - 返回类型为const时，外面所接的变量也必须设定为const类型。

- 面向过程编程，是将功能（即函数）封装，通过功能之间的复用和泛型来提高编程效率。

**I just don't want this happen** 
