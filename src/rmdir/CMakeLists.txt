add_executable(
	rmdir
	rmdir.cc
)

target_link_libraries(
	rmdir
	PRIVATE
	fmt::fmt
	gflags::gflags
	absl::strings
)
