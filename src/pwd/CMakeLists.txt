add_executable(
	pwd
	pwd.cc
)

target_link_libraries(
	pwd
	PRIVATE
	fmt::fmt
)
