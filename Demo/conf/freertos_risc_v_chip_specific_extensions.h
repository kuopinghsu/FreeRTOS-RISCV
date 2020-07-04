#ifndef __SET_EXTENSIONS_H__
#define __SET_EXTENSIONS_H__

#define portasmHAS_MTIME 0
#define portasmHANDLE_INTERRUPT 0

#define portasmADDITIONAL_CONTEXT_SIZE 0 /* Must be even number on 32-bit cores. */

.macro portasmSAVE_ADDITIONAL_REGISTERS
    /* No additional registers to save, so this macro does nothing. */
    .endm

.macro portasmRESTORE_ADDITIONAL_REGISTERS
    /* No additional registers to restore, so this macro does nothing. */
    .endm

#endif // __SET_EXTENSIONS_H__

