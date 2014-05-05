#include "tree_sitter/parser.h"

#define STATE_COUNT 32
#define SYMBOL_COUNT 18

enum {
    ts_sym_expression = 2,
    ts_sym_sum = 3,
    ts_sym_difference = 4,
    ts_sym_product = 5,
    ts_sym_quotient = 6,
    ts_sym_exponent = 7,
    ts_sym_group = 8,
    ts_sym_number = 9,
    ts_sym_variable = 10,
    ts_aux_sym_token0 = 11,
    ts_aux_sym_token1 = 12,
    ts_aux_sym_token2 = 13,
    ts_aux_sym_token3 = 14,
    ts_aux_sym_token4 = 15,
    ts_aux_sym_token5 = 16,
    ts_aux_sym_token6 = 17,
};

SYMBOL_NAMES = {
    [ts_sym_expression] = "expression",
    [ts_sym_sum] = "sum",
    [ts_sym_difference] = "difference",
    [ts_sym_product] = "product",
    [ts_sym_quotient] = "quotient",
    [ts_sym_exponent] = "exponent",
    [ts_sym_group] = "group",
    [ts_builtin_sym_error] = "error",
    [ts_builtin_sym_end] = "end",
    [ts_sym_number] = "number",
    [ts_sym_variable] = "variable",
    [ts_aux_sym_token0] = "'+'",
    [ts_aux_sym_token1] = "'-'",
    [ts_aux_sym_token2] = "'*'",
    [ts_aux_sym_token3] = "'/'",
    [ts_aux_sym_token4] = "'^'",
    [ts_aux_sym_token5] = "'('",
    [ts_aux_sym_token6] = "')'",
};

HIDDEN_SYMBOLS = {
    [ts_aux_sym_token0] = 1,
    [ts_aux_sym_token1] = 1,
    [ts_aux_sym_token2] = 1,
    [ts_aux_sym_token3] = 1,
    [ts_aux_sym_token4] = 1,
    [ts_aux_sym_token5] = 1,
    [ts_aux_sym_token6] = 1,
};

LEX_FN() {
    START_LEXER();
    switch (lex_state) {
        case 0:
            START_TOKEN();
            if (('\t' <= lookahead && lookahead <= '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(0);
            if (lookahead == '(')
                ADVANCE(1);
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(2);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(3);
            LEX_ERROR();
        case 1:
            ACCEPT_TOKEN(ts_aux_sym_token5);
        case 2:
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(2);
            ACCEPT_TOKEN(ts_sym_number);
        case 3:
            if (('0' <= lookahead && lookahead <= '9') ||
                ('A' <= lookahead && lookahead <= 'Z') ||
                (lookahead == '_') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(3);
            ACCEPT_TOKEN(ts_sym_variable);
        case 4:
            START_TOKEN();
            if (lookahead == '\0')
                ADVANCE(5);
            if (('\t' <= lookahead && lookahead <= '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(4);
            if (lookahead == '*')
                ADVANCE(6);
            if (lookahead == '+')
                ADVANCE(7);
            if (lookahead == '-')
                ADVANCE(8);
            if (lookahead == '/')
                ADVANCE(9);
            if (lookahead == '^')
                ADVANCE(10);
            LEX_ERROR();
        case 5:
            ACCEPT_TOKEN(ts_builtin_sym_end);
        case 6:
            ACCEPT_TOKEN(ts_aux_sym_token2);
        case 7:
            ACCEPT_TOKEN(ts_aux_sym_token0);
        case 8:
            ACCEPT_TOKEN(ts_aux_sym_token1);
        case 9:
            ACCEPT_TOKEN(ts_aux_sym_token3);
        case 10:
            ACCEPT_TOKEN(ts_aux_sym_token4);
        case 11:
            START_TOKEN();
            if (('\t' <= lookahead && lookahead <= '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(11);
            if (lookahead == ')')
                ADVANCE(12);
            if (lookahead == '*')
                ADVANCE(6);
            if (lookahead == '+')
                ADVANCE(7);
            if (lookahead == '-')
                ADVANCE(8);
            if (lookahead == '/')
                ADVANCE(9);
            if (lookahead == '^')
                ADVANCE(10);
            LEX_ERROR();
        case 12:
            ACCEPT_TOKEN(ts_aux_sym_token6);
        case 13:
            START_TOKEN();
            if ((lookahead == '\t') ||
                (lookahead == '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(13);
            if (lookahead == ')')
                ADVANCE(12);
            LEX_ERROR();
        case 14:
            START_TOKEN();
            if (lookahead == '\0')
                ADVANCE(5);
            if (('\t' <= lookahead && lookahead <= '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(14);
            if (lookahead == '(')
                ADVANCE(1);
            if (lookahead == ')')
                ADVANCE(12);
            if (lookahead == '*')
                ADVANCE(6);
            if (lookahead == '+')
                ADVANCE(7);
            if (lookahead == '-')
                ADVANCE(8);
            if (lookahead == '/')
                ADVANCE(9);
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(2);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(3);
            if (lookahead == '^')
                ADVANCE(10);
            LEX_ERROR();
        case ts_lex_state_error:
            START_TOKEN();
            if (lookahead == '\0')
                ADVANCE(5);
            if (('\t' <= lookahead && lookahead <= '\n') ||
                (lookahead == '\r') ||
                (lookahead == ' '))
                ADVANCE(14);
            if (lookahead == '(')
                ADVANCE(1);
            if (lookahead == ')')
                ADVANCE(12);
            if (lookahead == '*')
                ADVANCE(6);
            if (lookahead == '+')
                ADVANCE(7);
            if (lookahead == '-')
                ADVANCE(8);
            if (lookahead == '/')
                ADVANCE(9);
            if ('0' <= lookahead && lookahead <= '9')
                ADVANCE(2);
            if (('A' <= lookahead && lookahead <= 'Z') ||
                ('a' <= lookahead && lookahead <= 'z'))
                ADVANCE(3);
            if (lookahead == '^')
                ADVANCE(10);
            LEX_ERROR();
        default:
            LEX_PANIC();
    }
}

LEX_STATES = {
    [0] = 0,
    [1] = 4,
    [2] = 0,
    [3] = 4,
    [4] = 0,
    [5] = 4,
    [6] = 0,
    [7] = 4,
    [8] = 0,
    [9] = 4,
    [10] = 0,
    [11] = 4,
    [12] = 4,
    [13] = 0,
    [14] = 11,
    [15] = 0,
    [16] = 11,
    [17] = 0,
    [18] = 11,
    [19] = 0,
    [20] = 11,
    [21] = 0,
    [22] = 11,
    [23] = 0,
    [24] = 11,
    [25] = 11,
    [26] = 0,
    [27] = 11,
    [28] = 11,
    [29] = 13,
    [30] = 4,
    [31] = 13,
};

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"

PARSE_TABLE = {
    [0] = {
        [ts_sym_expression] = SHIFT(1),
        [ts_sym_sum] = SHIFT(12),
        [ts_sym_difference] = SHIFT(12),
        [ts_sym_product] = SHIFT(12),
        [ts_sym_quotient] = SHIFT(12),
        [ts_sym_exponent] = SHIFT(12),
        [ts_sym_group] = SHIFT(12),
        [ts_sym_number] = SHIFT(12),
        [ts_sym_variable] = SHIFT(12),
        [ts_aux_sym_token5] = SHIFT(13),
    },
    [1] = {
        [ts_builtin_sym_end] = ACCEPT_INPUT(),
        [ts_aux_sym_token0] = SHIFT(2),
        [ts_aux_sym_token1] = SHIFT(4),
        [ts_aux_sym_token2] = SHIFT(6),
        [ts_aux_sym_token3] = SHIFT(8),
        [ts_aux_sym_token4] = SHIFT(10),
    },
    [2] = {
        [ts_sym_expression] = SHIFT(3),
        [ts_sym_sum] = SHIFT(12),
        [ts_sym_difference] = SHIFT(12),
        [ts_sym_product] = SHIFT(12),
        [ts_sym_quotient] = SHIFT(12),
        [ts_sym_exponent] = SHIFT(12),
        [ts_sym_group] = SHIFT(12),
        [ts_sym_number] = SHIFT(12),
        [ts_sym_variable] = SHIFT(12),
        [ts_aux_sym_token5] = SHIFT(13),
    },
    [3] = {
        [ts_builtin_sym_end] = REDUCE(ts_sym_sum, 3),
        [ts_aux_sym_token0] = SHIFT(2),
        [ts_aux_sym_token1] = SHIFT(4),
        [ts_aux_sym_token2] = SHIFT(6),
        [ts_aux_sym_token3] = SHIFT(8),
        [ts_aux_sym_token4] = SHIFT(10),
    },
    [4] = {
        [ts_sym_expression] = SHIFT(5),
        [ts_sym_sum] = SHIFT(12),
        [ts_sym_difference] = SHIFT(12),
        [ts_sym_product] = SHIFT(12),
        [ts_sym_quotient] = SHIFT(12),
        [ts_sym_exponent] = SHIFT(12),
        [ts_sym_group] = SHIFT(12),
        [ts_sym_number] = SHIFT(12),
        [ts_sym_variable] = SHIFT(12),
        [ts_aux_sym_token5] = SHIFT(13),
    },
    [5] = {
        [ts_builtin_sym_end] = REDUCE(ts_sym_difference, 3),
        [ts_aux_sym_token0] = SHIFT(2),
        [ts_aux_sym_token1] = SHIFT(4),
        [ts_aux_sym_token2] = SHIFT(6),
        [ts_aux_sym_token3] = SHIFT(8),
        [ts_aux_sym_token4] = SHIFT(10),
    },
    [6] = {
        [ts_sym_expression] = SHIFT(7),
        [ts_sym_sum] = SHIFT(12),
        [ts_sym_difference] = SHIFT(12),
        [ts_sym_product] = SHIFT(12),
        [ts_sym_quotient] = SHIFT(12),
        [ts_sym_exponent] = SHIFT(12),
        [ts_sym_group] = SHIFT(12),
        [ts_sym_number] = SHIFT(12),
        [ts_sym_variable] = SHIFT(12),
        [ts_aux_sym_token5] = SHIFT(13),
    },
    [7] = {
        [ts_builtin_sym_end] = REDUCE(ts_sym_product, 3),
        [ts_aux_sym_token0] = REDUCE(ts_sym_product, 3),
        [ts_aux_sym_token1] = REDUCE(ts_sym_product, 3),
        [ts_aux_sym_token2] = SHIFT(6),
        [ts_aux_sym_token3] = SHIFT(8),
        [ts_aux_sym_token4] = SHIFT(10),
    },
    [8] = {
        [ts_sym_expression] = SHIFT(9),
        [ts_sym_sum] = SHIFT(12),
        [ts_sym_difference] = SHIFT(12),
        [ts_sym_product] = SHIFT(12),
        [ts_sym_quotient] = SHIFT(12),
        [ts_sym_exponent] = SHIFT(12),
        [ts_sym_group] = SHIFT(12),
        [ts_sym_number] = SHIFT(12),
        [ts_sym_variable] = SHIFT(12),
        [ts_aux_sym_token5] = SHIFT(13),
    },
    [9] = {
        [ts_builtin_sym_end] = REDUCE(ts_sym_quotient, 3),
        [ts_aux_sym_token0] = REDUCE(ts_sym_quotient, 3),
        [ts_aux_sym_token1] = REDUCE(ts_sym_quotient, 3),
        [ts_aux_sym_token2] = SHIFT(6),
        [ts_aux_sym_token3] = SHIFT(8),
        [ts_aux_sym_token4] = SHIFT(10),
    },
    [10] = {
        [ts_sym_expression] = SHIFT(11),
        [ts_sym_sum] = SHIFT(12),
        [ts_sym_difference] = SHIFT(12),
        [ts_sym_product] = SHIFT(12),
        [ts_sym_quotient] = SHIFT(12),
        [ts_sym_exponent] = SHIFT(12),
        [ts_sym_group] = SHIFT(12),
        [ts_sym_number] = SHIFT(12),
        [ts_sym_variable] = SHIFT(12),
        [ts_aux_sym_token5] = SHIFT(13),
    },
    [11] = {
        [ts_builtin_sym_end] = REDUCE(ts_sym_exponent, 3),
        [ts_aux_sym_token0] = REDUCE(ts_sym_exponent, 3),
        [ts_aux_sym_token1] = REDUCE(ts_sym_exponent, 3),
        [ts_aux_sym_token2] = REDUCE(ts_sym_exponent, 3),
        [ts_aux_sym_token3] = REDUCE(ts_sym_exponent, 3),
        [ts_aux_sym_token4] = SHIFT(10),
    },
    [12] = {
        [ts_builtin_sym_end] = REDUCE(ts_sym_expression, 1),
        [ts_aux_sym_token0] = REDUCE(ts_sym_expression, 1),
        [ts_aux_sym_token1] = REDUCE(ts_sym_expression, 1),
        [ts_aux_sym_token2] = REDUCE(ts_sym_expression, 1),
        [ts_aux_sym_token3] = REDUCE(ts_sym_expression, 1),
        [ts_aux_sym_token4] = REDUCE(ts_sym_expression, 1),
    },
    [13] = {
        [ts_sym_expression] = SHIFT(14),
        [ts_sym_sum] = SHIFT(25),
        [ts_sym_difference] = SHIFT(25),
        [ts_sym_product] = SHIFT(25),
        [ts_sym_quotient] = SHIFT(25),
        [ts_sym_exponent] = SHIFT(25),
        [ts_sym_group] = SHIFT(25),
        [ts_builtin_sym_error] = SHIFT(31),
        [ts_sym_number] = SHIFT(25),
        [ts_sym_variable] = SHIFT(25),
        [ts_aux_sym_token5] = SHIFT(26),
    },
    [14] = {
        [ts_aux_sym_token0] = SHIFT(15),
        [ts_aux_sym_token1] = SHIFT(17),
        [ts_aux_sym_token2] = SHIFT(19),
        [ts_aux_sym_token3] = SHIFT(21),
        [ts_aux_sym_token4] = SHIFT(23),
        [ts_aux_sym_token6] = SHIFT(30),
    },
    [15] = {
        [ts_sym_expression] = SHIFT(16),
        [ts_sym_sum] = SHIFT(25),
        [ts_sym_difference] = SHIFT(25),
        [ts_sym_product] = SHIFT(25),
        [ts_sym_quotient] = SHIFT(25),
        [ts_sym_exponent] = SHIFT(25),
        [ts_sym_group] = SHIFT(25),
        [ts_sym_number] = SHIFT(25),
        [ts_sym_variable] = SHIFT(25),
        [ts_aux_sym_token5] = SHIFT(26),
    },
    [16] = {
        [ts_aux_sym_token0] = SHIFT(15),
        [ts_aux_sym_token1] = SHIFT(17),
        [ts_aux_sym_token2] = SHIFT(19),
        [ts_aux_sym_token3] = SHIFT(21),
        [ts_aux_sym_token4] = SHIFT(23),
        [ts_aux_sym_token6] = REDUCE(ts_sym_sum, 3),
    },
    [17] = {
        [ts_sym_expression] = SHIFT(18),
        [ts_sym_sum] = SHIFT(25),
        [ts_sym_difference] = SHIFT(25),
        [ts_sym_product] = SHIFT(25),
        [ts_sym_quotient] = SHIFT(25),
        [ts_sym_exponent] = SHIFT(25),
        [ts_sym_group] = SHIFT(25),
        [ts_sym_number] = SHIFT(25),
        [ts_sym_variable] = SHIFT(25),
        [ts_aux_sym_token5] = SHIFT(26),
    },
    [18] = {
        [ts_aux_sym_token0] = SHIFT(15),
        [ts_aux_sym_token1] = SHIFT(17),
        [ts_aux_sym_token2] = SHIFT(19),
        [ts_aux_sym_token3] = SHIFT(21),
        [ts_aux_sym_token4] = SHIFT(23),
        [ts_aux_sym_token6] = REDUCE(ts_sym_difference, 3),
    },
    [19] = {
        [ts_sym_expression] = SHIFT(20),
        [ts_sym_sum] = SHIFT(25),
        [ts_sym_difference] = SHIFT(25),
        [ts_sym_product] = SHIFT(25),
        [ts_sym_quotient] = SHIFT(25),
        [ts_sym_exponent] = SHIFT(25),
        [ts_sym_group] = SHIFT(25),
        [ts_sym_number] = SHIFT(25),
        [ts_sym_variable] = SHIFT(25),
        [ts_aux_sym_token5] = SHIFT(26),
    },
    [20] = {
        [ts_aux_sym_token0] = REDUCE(ts_sym_product, 3),
        [ts_aux_sym_token1] = REDUCE(ts_sym_product, 3),
        [ts_aux_sym_token2] = SHIFT(19),
        [ts_aux_sym_token3] = SHIFT(21),
        [ts_aux_sym_token4] = SHIFT(23),
        [ts_aux_sym_token6] = REDUCE(ts_sym_product, 3),
    },
    [21] = {
        [ts_sym_expression] = SHIFT(22),
        [ts_sym_sum] = SHIFT(25),
        [ts_sym_difference] = SHIFT(25),
        [ts_sym_product] = SHIFT(25),
        [ts_sym_quotient] = SHIFT(25),
        [ts_sym_exponent] = SHIFT(25),
        [ts_sym_group] = SHIFT(25),
        [ts_sym_number] = SHIFT(25),
        [ts_sym_variable] = SHIFT(25),
        [ts_aux_sym_token5] = SHIFT(26),
    },
    [22] = {
        [ts_aux_sym_token0] = REDUCE(ts_sym_quotient, 3),
        [ts_aux_sym_token1] = REDUCE(ts_sym_quotient, 3),
        [ts_aux_sym_token2] = SHIFT(19),
        [ts_aux_sym_token3] = SHIFT(21),
        [ts_aux_sym_token4] = SHIFT(23),
        [ts_aux_sym_token6] = REDUCE(ts_sym_quotient, 3),
    },
    [23] = {
        [ts_sym_expression] = SHIFT(24),
        [ts_sym_sum] = SHIFT(25),
        [ts_sym_difference] = SHIFT(25),
        [ts_sym_product] = SHIFT(25),
        [ts_sym_quotient] = SHIFT(25),
        [ts_sym_exponent] = SHIFT(25),
        [ts_sym_group] = SHIFT(25),
        [ts_sym_number] = SHIFT(25),
        [ts_sym_variable] = SHIFT(25),
        [ts_aux_sym_token5] = SHIFT(26),
    },
    [24] = {
        [ts_aux_sym_token0] = REDUCE(ts_sym_exponent, 3),
        [ts_aux_sym_token1] = REDUCE(ts_sym_exponent, 3),
        [ts_aux_sym_token2] = REDUCE(ts_sym_exponent, 3),
        [ts_aux_sym_token3] = REDUCE(ts_sym_exponent, 3),
        [ts_aux_sym_token4] = SHIFT(23),
        [ts_aux_sym_token6] = REDUCE(ts_sym_exponent, 3),
    },
    [25] = {
        [ts_aux_sym_token0] = REDUCE(ts_sym_expression, 1),
        [ts_aux_sym_token1] = REDUCE(ts_sym_expression, 1),
        [ts_aux_sym_token2] = REDUCE(ts_sym_expression, 1),
        [ts_aux_sym_token3] = REDUCE(ts_sym_expression, 1),
        [ts_aux_sym_token4] = REDUCE(ts_sym_expression, 1),
        [ts_aux_sym_token6] = REDUCE(ts_sym_expression, 1),
    },
    [26] = {
        [ts_sym_expression] = SHIFT(27),
        [ts_sym_sum] = SHIFT(25),
        [ts_sym_difference] = SHIFT(25),
        [ts_sym_product] = SHIFT(25),
        [ts_sym_quotient] = SHIFT(25),
        [ts_sym_exponent] = SHIFT(25),
        [ts_sym_group] = SHIFT(25),
        [ts_builtin_sym_error] = SHIFT(29),
        [ts_sym_number] = SHIFT(25),
        [ts_sym_variable] = SHIFT(25),
        [ts_aux_sym_token5] = SHIFT(26),
    },
    [27] = {
        [ts_aux_sym_token0] = SHIFT(15),
        [ts_aux_sym_token1] = SHIFT(17),
        [ts_aux_sym_token2] = SHIFT(19),
        [ts_aux_sym_token3] = SHIFT(21),
        [ts_aux_sym_token4] = SHIFT(23),
        [ts_aux_sym_token6] = SHIFT(28),
    },
    [28] = {
        [ts_aux_sym_token0] = REDUCE(ts_sym_group, 3),
        [ts_aux_sym_token1] = REDUCE(ts_sym_group, 3),
        [ts_aux_sym_token2] = REDUCE(ts_sym_group, 3),
        [ts_aux_sym_token3] = REDUCE(ts_sym_group, 3),
        [ts_aux_sym_token4] = REDUCE(ts_sym_group, 3),
        [ts_aux_sym_token6] = REDUCE(ts_sym_group, 3),
    },
    [29] = {
        [ts_aux_sym_token6] = SHIFT(28),
    },
    [30] = {
        [ts_builtin_sym_end] = REDUCE(ts_sym_group, 3),
        [ts_aux_sym_token0] = REDUCE(ts_sym_group, 3),
        [ts_aux_sym_token1] = REDUCE(ts_sym_group, 3),
        [ts_aux_sym_token2] = REDUCE(ts_sym_group, 3),
        [ts_aux_sym_token3] = REDUCE(ts_sym_group, 3),
        [ts_aux_sym_token4] = REDUCE(ts_sym_group, 3),
    },
    [31] = {
        [ts_aux_sym_token6] = SHIFT(30),
    },
};

#pragma GCC diagnostic pop

EXPORT_PARSER(ts_parser_arithmetic);
