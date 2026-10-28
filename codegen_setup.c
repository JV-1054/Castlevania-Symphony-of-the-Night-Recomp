/* Title config for psxrecomp/host/psxrecomp_codegen_host.
 * Wired only when the build opts into -DPSX_SETUP_WIZARD=ON. */

#include "codegen_setup.h"

#include "psxrecomp_codegen_host.h"

static const PsxrecompCodegenHostConfig kCodegenConfig = {
    .display_name = "Castlevania: Symphony of the Night",
    .project_root_env = "CASTLEVANIA_SYMPHONY_OF_THE_NIGHT_RECOMP_PROJECT_ROOT",
    .build_dir_env = "CASTLEVANIA_SYMPHONY_OF_THE_NIGHT_RECOMP_BUILD_DIR",
    .force_setup_env = "CASTLEVANIA_SYMPHONY_OF_THE_NIGHT_RECOMP_FORCE_SETUP",
    .psxrecomp_cli_relpath = "psxrecomp/psxrecomp_cli.py",
    .seed_cfg_relpath = "game.toml",
    .game_toml_relpath = "game.toml",
    .gen_marker_relpath = "generated/SLUS_000.67_dispatch.c",
    .build_dir_name = "build-sotn",
    .cmake_target = "psx-runtime",
    .exe_basename = "Castlevania_Symphony_of_the_Night_Recompiled",
    .prepare_note =
        "Uses your legal disc with the local psxrecomp SDK to generate "
        "BIOS + game C, then cmake --build. The product lives under "
        "build-sotn/; reopening this setup exe forwards there.",
    .prepare_note_windows =
        "Uses your legal disc with the local psxrecomp SDK to generate "
        "BIOS + game C, then quits and rebuilds via a helper. Afterward, "
        "this setup exe forwards to build-sotn/ (bios, mods, settings).",
    .prepare_note_no_cmake =
        "Uses your legal disc with the local psxrecomp SDK to generate "
        "BIOS + game C. Rebuild into build-sotn/, then relaunch this "
        "setup exe (it forwards to the product build).",
};

void psx_game_codegen_setup_apply(RecompLauncherCGameInfo *gi) {
  psxrecomp_codegen_host_apply(gi, &kCodegenConfig);
}

void psx_game_codegen_relaunch_or_exit(const char *disc_path) {
  psxrecomp_codegen_host_relaunch_or_exit(disc_path);
}

void psx_game_codegen_forward_if_built(int argc, char **argv) {
  psxrecomp_codegen_host_forward_if_built(&kCodegenConfig, argc, argv);
}
