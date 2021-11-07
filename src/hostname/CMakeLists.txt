add_executable(
	hostname
	hostname.cc
)

target_link_libraries(
	hostname
	PRIVATE
	fmt::fmt
	gflags::gflags
)
