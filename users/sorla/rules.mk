SRC += sorla.c
SRC += combos.def
COMBO_ENABLE = yes
AUTO_SHIFT_ENABLE = yes

VPATH += keyboards/gboards


ifeq ($(strip $(REPEAT_KEY_ENABLE)), yes)
    OPT_DEFS += -DREPEAT_KEY_ENABLED
endif
ifeq ($(strip $(MACROS_ENABLED)), yes)
    OPT_DEFS += -DMACROS_ENABLED
endif
