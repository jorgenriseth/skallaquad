add_executable(test_suite_skallaquad
    test_trapezoid.c
)
target_link_libraries(test_suite_skallaquad
    skallaquad
    Unity
    m
)

add_test(test_skallaquad test_suite_skallaquad)
