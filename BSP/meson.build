# BSP

# internal incdirs and srcsfiles
bsp_incdirs = []
bsp_srcs    = []

bsp_incdirs += include_directories('EFR32MG12P/Devices/Include')
bsp_incdirs += include_directories('CMSIS')
bsp_incdirs += include_directories('emlib/inc')

# sources
bsp_srcs += ['device/system_efr32mg12p.c']

bsp_srcs += ['emlib/src/em_cmu.c']
bsp_srcs += ['emlib/src/em_gpio.c']
#=============================================================================#

bsp_srcs = files(bsp_srcs)

# use the variables bsp_srcs and bsp_incdirs for the executable