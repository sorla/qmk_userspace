SRC += sorla.c
# SRC += combos.def

VPATH += keyboards/gboards


ifeq ($(strip $(REPEAT_KEY_ENABLE)), yes)
    OPT_DEFS += -DREPEAT_KEY_ENABLED
endif
ifeq ($(strip $(MACROS_ENABLED)), yes)
    OPT_DEFS += -DMACROS_ENABLED
endif
ifeq ($(strip $(COMBO_ENABLE)), yes)
    OPT_DEFS += -DCOMBOS_ENABLED
endif
ifeq ($(strip $(AUTO_SHIFT_ENABLE)), yes)
    OPT_DEFS += -DAUTO_SHIFT_ENABLED
endif
