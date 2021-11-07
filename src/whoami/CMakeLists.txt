add_executable(
	whoami
	whoami.cc
)

target_link_libraries(
	whoami
	PRIVATE
	fmt::fmt
)
