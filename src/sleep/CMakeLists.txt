add_executable(
	sleep
	sleep.cc
)

target_link_libraries(
	sleep
	PRIVATE
	fmt::fmt
	gflags::gflags
)
