#ifndef BITWISE_OPERATION_H
#define BITWISE_OPERATION_H

#define SET_BIT(Register, Bit)          Register |= (1 << (Bit))
#define CLEAR_BIT(Register, Bit)        Register &= ~(1 << (Bit))
#define TOGGLE_BIT(Register, Bit)       Register ^= (1 << (Bit))
#define GET_BIT(Register, Bit)          (Register & (1<<(Bit)))

#endif