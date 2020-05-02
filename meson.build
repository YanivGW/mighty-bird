project('mighty_bird', 'c')

#==============================================================================#
# Initialize some globals
project_name  = 'mighty_bird'
srcs          = []
incdirs       = []
c_args        = []
link_args     = []
link_deps     = []

#==============================================================================#
# Preprocessor macros
c_args     += '-DARM_MATH_CM4'
c_args     += '-Dflash_layout'
c_args     += '-DEFR32MG12P332F1024GL125'

#==============================================================================#
linkfiles   = files(['linker-script/EFR32MG12P332F1024GL125_flash.lds'])
startupfile = files(['BSP/device/startup_efr32mg12p.c'])

incdirs += include_directories('C:/Program Files (x86)/GNU Tools Arm Embedded/9 2019-q4-major/arm-none-eabi/include')

#==============================================================================#
# create Debug Flags, depending on meson buildtype
c_args += get_option('buildtype') == 'release' ? '-DNDEBUG' : '-DDEBUG'

#==============================================================================#
# parse linkerfiles to a linker commando
foreach linkfile : linkfiles
 link_args += ['-Wl,-T,@0@/@1@'.format(meson.current_source_dir(), linkfile)]
endforeach

#==============================================================================#
# add BSP include dirs & srcs
subdir('BSP')

#==============================================================================#
elf = executable(
            project_name,
            [srcs, bsp_srcs, 'main.c', startupfile] ,
            name_suffix         : 'elf',
            c_args              : [c_args ],
            link_args           : [link_args, '-Wl,--gc-sections'],
            dependencies        : link_deps,
            include_directories : [incdirs, bsp_incdirs] )

#==============================================================================#
# create custom target : create binary
mainbin = custom_target(
                        project_name + '.bin',
    output           : [project_name + '.bin'],
    build_by_default : true,
    command          : ['objcopy', '-O', 'binary', project_name + '.elf', project_name + '.bin'],
    depends          : [elf])