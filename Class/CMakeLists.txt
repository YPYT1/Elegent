# Class 目录的 CMakeLists.txt

# Sequential 可执行文件
add_executable(Sequential LInkedLIst/Sequential_List.cpp)

# Sqlist 可执行文件
add_executable(Sqlist LInkedLIst/Sqlist.cpp)

# LinkList 可执行文件
add_executable(LinkList LInkedLIst/LinkList.cpp LInkedLIst/LinkList.h)

# LinkList_app 可执行文件
add_executable(LinkList_app LInkedLIst/LInkList_app.cpp LInkedLIst/LInkList_app.h)

# Maopao 可执行文件
add_executable(maopao LInkedLIst/maopao.cpp LInkedLIst/maopao.h)

# Poly 可执行文件
add_executable(poly LInkedLIst/poly.cpp LInkedLIst/poly.h)

# Stack 可执行文件
add_executable(stack stack/stack.cpp stack/stack.h)
add_executable(queueclass Queue/queue.cpp Queue/queue.h)
add_executable(LinkQueue Queue/LinkQueue.cpp Queue/LinkQueue.h)
add_executable(class_LinkQueue Queue/class_LinkQueue.cpp Queue/class_LinkQueue.h)
add_executable(LinkQueue_App Queue/LinkQueue_App.cpp Queue/LinkQueue_App.h)