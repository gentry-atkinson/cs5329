final_project: build_lists final_project_problem1

build_lists: build_lists.cpp
		g++ -o build_lists build_lists.cpp

final_project_problem1: atkinson_finalProject_problem1.cpp
	g++ -o final_project atkinson_finalProject_problem1.cpp
