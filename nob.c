#define NOB_IMPLEMENTATION

#include "nob.h"

#define BUILD_FOLDER "build/"
#define SRC_FOLDER   "src/"

int main(int argc, char **argv) {
    NOB_GO_REBUILD_URSELF(argc, argv);

    if (!nob_mkdir_if_not_exists(BUILD_FOLDER)) return 1;

	Nob_Cmd cmd = {0};
	nob_cmd_append(&cmd, "clang","-Wall", "-Wextra", "-o", BUILD_FOLDER"three-body", SRC_FOLDER"three-body.c");
	nob_cmd_append(&cmd, "-I./deps/macos_arm", "-Ldeps/macos_arm/", "deps/macos_arm/libraylib.a");
	nob_cmd_append(&cmd, "-framework", "CoreVideo");
	nob_cmd_append(&cmd, "-framework", "IOKit");
	nob_cmd_append(&cmd, "-framework", "Cocoa");
	nob_cmd_append(&cmd, "-framework", "GLUT");
	nob_cmd_append(&cmd,  "-framework", "OpenGL");

	if (!nob_cmd_run(&cmd)) return 1;

	nob_cmd_append(&cmd, "./build/three-body");
	if (!nob_cmd_run(&cmd)) return 1;

	return 0;
}
