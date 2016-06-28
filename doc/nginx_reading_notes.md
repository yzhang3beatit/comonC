## Nginx reading notes
---

1. 命名中，所有文件，函数，以及全局变量中，都以ngx开始，用以标识nginx自己的实现。
1. 封装的malloc，还可以做什么？
  1. 当malloc返回NULL的时候，要使用log记录现场；
  2. 还可以增加debug的log函数记录，成功分配的内存地址以及长度。
  3. 不论是否成功，都只是返回；
1. 为了追求性能，ngx_array_init被定义为inline；同时还在C文件里定义了ngx_array_create不只是分配内存空间，还做了初始化；
1. 为了追求性能，列表结点ngx_list_part_t除了定义数据区和next指针，还定义了nelts，用来存储已存储元素个数。就是为了省去遍历链表计算长度的过程。ngx_list_t还定义了last指针，直接表示最后一个节点的位置
1. ngx自定义的错误码，非常简单只有6个，分别是error，again，busy，done，declined和abort；同时它也同时支持系统级所有的errno；而且为了减少strerror的调用，ngx会把系统中所有支持的errno对应的字符串，都存储到一个数组里。这是在main的init里执行的。
1. ngx中处理命令行参数，首先是用for遍历argc，以‘-’作为参数的标志，然后使用while遍历其后的所有的‘?hvVtqpcgs’；这样做就是为了能够使用一个‘-’拖一串标志位。在ngx_get_options函数中，完全没有调用任何执行函数，而只是对static全局变量进行赋值
1. 最简单的封装ngx函数的方法，就是用类似的宏#define ngx_getpid getpid

