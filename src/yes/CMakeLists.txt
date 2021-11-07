add_executable(
	yes
	yes.cc
)

target_link_libraries(
	yes
	PRIVATE
	fmt::fmt
)
