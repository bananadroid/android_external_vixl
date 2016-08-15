// Copyright 2016, VIXL authors
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//   * Redistributions of source code must retain the above copyright notice,
//     this list of conditions and the following disclaimer.
//   * Redistributions in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//   * Neither the name of ARM Limited nor the names of its contributors may be
//     used to endorse or promote products derived from this software without
//     specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


// -----------------------------------------------------------------------------
// This file is auto generated from the
// test/aarch32/config/template-assembler-aarch32.cc.in template file using
// tools/generate_tests.py.
//
// PLEASE DO NOT EDIT.
// -----------------------------------------------------------------------------


#include "test-runner.h"

#include "test-utils.h"
#include "test-utils-aarch32.h"

#include "aarch32/assembler-aarch32.h"
#include "aarch32/macro-assembler-aarch32.h"

#define BUF_SIZE (4096)

namespace vixl {
namespace aarch32 {

// List of instruction mnemonics.
#define FOREACH_INSTRUCTION(M) \
  M(Cmn)                       \
  M(Cmp)                       \
  M(Mov)                       \
  M(Movs)                      \
  M(Mvn)                       \
  M(Mvns)                      \
  M(Teq)                       \
  M(Tst)


// Values to be passed to the assembler to produce the instruction under test.
struct Operands {
  Condition cond;
  Register rd;
  Register rn;
  ShiftType shift;
  uint32_t amount;
};

// This structure contains all data needed to test one specific
// instruction.
struct TestData {
  // The `operands` field represents what to pass to the assembler to
  // produce the instruction.
  Operands operands;
  // Optionally expect the MacroAssembler to have generated an extra
  // instruction. This is used when the instruction needs to be in an IT block.
  const char* expect_instruction_before;
  // Description of the operands, used for error reporting.
  const char* operands_description;
  // Unique identifier, used for generating traces.
  const char* identifier;
};

struct TestResult {
  size_t size;
  const byte* encoding;
};

// Each element of this array produce one instruction encoding.
static const TestData kTests[] =
    {{{al, r7, r7, LSR, 5}, "", "al r7 r7 LSR 5", "al_r7_r7_LSR_5"},
     {{al, r0, r3, ASR, 30}, "", "al r0 r3 ASR 30", "al_r0_r3_ASR_30"},
     {{al, r10, r5, ASR, 31}, "", "al r10 r5 ASR 31", "al_r10_r5_ASR_31"},
     {{al, r12, r9, ASR, 16}, "", "al r12 r9 ASR 16", "al_r12_r9_ASR_16"},
     {{al, r5, r3, ASR, 31}, "", "al r5 r3 ASR 31", "al_r5_r3_ASR_31"},
     {{al, r10, r8, ASR, 10}, "", "al r10 r8 ASR 10", "al_r10_r8_ASR_10"},
     {{al, r6, r7, LSR, 11}, "", "al r6 r7 LSR 11", "al_r6_r7_LSR_11"},
     {{al, r13, r12, ASR, 31}, "", "al r13 r12 ASR 31", "al_r13_r12_ASR_31"},
     {{al, r4, r0, ASR, 22}, "", "al r4 r0 ASR 22", "al_r4_r0_ASR_22"},
     {{al, r3, r10, ASR, 23}, "", "al r3 r10 ASR 23", "al_r3_r10_ASR_23"},
     {{al, r3, r11, LSR, 6}, "", "al r3 r11 LSR 6", "al_r3_r11_LSR_6"},
     {{al, r3, r0, LSR, 7}, "", "al r3 r0 LSR 7", "al_r3_r0_LSR_7"},
     {{al, r12, r14, LSR, 17}, "", "al r12 r14 LSR 17", "al_r12_r14_LSR_17"},
     {{al, r10, r7, ASR, 15}, "", "al r10 r7 ASR 15", "al_r10_r7_ASR_15"},
     {{al, r10, r8, LSR, 10}, "", "al r10 r8 LSR 10", "al_r10_r8_LSR_10"},
     {{al, r11, r1, LSR, 12}, "", "al r11 r1 LSR 12", "al_r11_r1_LSR_12"},
     {{al, r14, r3, ASR, 31}, "", "al r14 r3 ASR 31", "al_r14_r3_ASR_31"},
     {{al, r1, r3, LSR, 5}, "", "al r1 r3 LSR 5", "al_r1_r3_LSR_5"},
     {{al, r10, r14, ASR, 23}, "", "al r10 r14 ASR 23", "al_r10_r14_ASR_23"},
     {{al, r0, r0, LSR, 18}, "", "al r0 r0 LSR 18", "al_r0_r0_LSR_18"},
     {{al, r1, r5, LSR, 13}, "", "al r1 r5 LSR 13", "al_r1_r5_LSR_13"},
     {{al, r4, r2, LSR, 20}, "", "al r4 r2 LSR 20", "al_r4_r2_LSR_20"},
     {{al, r1, r6, ASR, 8}, "", "al r1 r6 ASR 8", "al_r1_r6_ASR_8"},
     {{al, r7, r1, LSR, 22}, "", "al r7 r1 LSR 22", "al_r7_r1_LSR_22"},
     {{al, r11, r9, LSR, 32}, "", "al r11 r9 LSR 32", "al_r11_r9_LSR_32"},
     {{al, r3, r5, LSR, 32}, "", "al r3 r5 LSR 32", "al_r3_r5_LSR_32"},
     {{al, r9, r3, LSR, 12}, "", "al r9 r3 LSR 12", "al_r9_r3_LSR_12"},
     {{al, r13, r10, LSR, 23}, "", "al r13 r10 LSR 23", "al_r13_r10_LSR_23"},
     {{al, r8, r11, ASR, 3}, "", "al r8 r11 ASR 3", "al_r8_r11_ASR_3"},
     {{al, r12, r1, ASR, 6}, "", "al r12 r1 ASR 6", "al_r12_r1_ASR_6"},
     {{al, r6, r9, ASR, 8}, "", "al r6 r9 ASR 8", "al_r6_r9_ASR_8"},
     {{al, r1, r12, LSR, 4}, "", "al r1 r12 LSR 4", "al_r1_r12_LSR_4"},
     {{al, r13, r7, ASR, 13}, "", "al r13 r7 ASR 13", "al_r13_r7_ASR_13"},
     {{al, r13, r10, LSR, 22}, "", "al r13 r10 LSR 22", "al_r13_r10_LSR_22"},
     {{al, r13, r2, LSR, 5}, "", "al r13 r2 LSR 5", "al_r13_r2_LSR_5"},
     {{al, r13, r2, LSR, 11}, "", "al r13 r2 LSR 11", "al_r13_r2_LSR_11"},
     {{al, r10, r0, ASR, 14}, "", "al r10 r0 ASR 14", "al_r10_r0_ASR_14"},
     {{al, r5, r8, LSR, 24}, "", "al r5 r8 LSR 24", "al_r5_r8_LSR_24"},
     {{al, r14, r1, ASR, 12}, "", "al r14 r1 ASR 12", "al_r14_r1_ASR_12"},
     {{al, r7, r3, ASR, 27}, "", "al r7 r3 ASR 27", "al_r7_r3_ASR_27"},
     {{al, r7, r0, LSR, 26}, "", "al r7 r0 LSR 26", "al_r7_r0_LSR_26"},
     {{al, r2, r0, ASR, 31}, "", "al r2 r0 ASR 31", "al_r2_r0_ASR_31"},
     {{al, r8, r0, ASR, 21}, "", "al r8 r0 ASR 21", "al_r8_r0_ASR_21"},
     {{al, r12, r7, ASR, 21}, "", "al r12 r7 ASR 21", "al_r12_r7_ASR_21"},
     {{al, r0, r10, LSR, 32}, "", "al r0 r10 LSR 32", "al_r0_r10_LSR_32"},
     {{al, r5, r5, LSR, 12}, "", "al r5 r5 LSR 12", "al_r5_r5_LSR_12"},
     {{al, r3, r10, LSR, 30}, "", "al r3 r10 LSR 30", "al_r3_r10_LSR_30"},
     {{al, r5, r6, ASR, 25}, "", "al r5 r6 ASR 25", "al_r5_r6_ASR_25"},
     {{al, r9, r4, LSR, 12}, "", "al r9 r4 LSR 12", "al_r9_r4_LSR_12"},
     {{al, r8, r10, ASR, 32}, "", "al r8 r10 ASR 32", "al_r8_r10_ASR_32"},
     {{al, r3, r4, ASR, 4}, "", "al r3 r4 ASR 4", "al_r3_r4_ASR_4"},
     {{al, r13, r2, LSR, 22}, "", "al r13 r2 LSR 22", "al_r13_r2_LSR_22"},
     {{al, r9, r7, LSR, 25}, "", "al r9 r7 LSR 25", "al_r9_r7_LSR_25"},
     {{al, r14, r12, ASR, 26}, "", "al r14 r12 ASR 26", "al_r14_r12_ASR_26"},
     {{al, r10, r0, LSR, 19}, "", "al r10 r0 LSR 19", "al_r10_r0_LSR_19"},
     {{al, r6, r8, LSR, 10}, "", "al r6 r8 LSR 10", "al_r6_r8_LSR_10"},
     {{al, r14, r12, ASR, 15}, "", "al r14 r12 ASR 15", "al_r14_r12_ASR_15"},
     {{al, r14, r14, LSR, 10}, "", "al r14 r14 LSR 10", "al_r14_r14_LSR_10"},
     {{al, r3, r2, ASR, 3}, "", "al r3 r2 ASR 3", "al_r3_r2_ASR_3"},
     {{al, r13, r6, ASR, 26}, "", "al r13 r6 ASR 26", "al_r13_r6_ASR_26"},
     {{al, r14, r9, LSR, 19}, "", "al r14 r9 LSR 19", "al_r14_r9_LSR_19"},
     {{al, r14, r6, ASR, 13}, "", "al r14 r6 ASR 13", "al_r14_r6_ASR_13"},
     {{al, r4, r8, LSR, 6}, "", "al r4 r8 LSR 6", "al_r4_r8_LSR_6"},
     {{al, r3, r11, LSR, 17}, "", "al r3 r11 LSR 17", "al_r3_r11_LSR_17"},
     {{al, r13, r8, ASR, 17}, "", "al r13 r8 ASR 17", "al_r13_r8_ASR_17"},
     {{al, r1, r13, ASR, 14}, "", "al r1 r13 ASR 14", "al_r1_r13_ASR_14"},
     {{al, r13, r7, ASR, 14}, "", "al r13 r7 ASR 14", "al_r13_r7_ASR_14"},
     {{al, r12, r11, ASR, 4}, "", "al r12 r11 ASR 4", "al_r12_r11_ASR_4"},
     {{al, r9, r11, LSR, 23}, "", "al r9 r11 LSR 23", "al_r9_r11_LSR_23"},
     {{al, r7, r0, ASR, 16}, "", "al r7 r0 ASR 16", "al_r7_r0_ASR_16"},
     {{al, r14, r13, ASR, 32}, "", "al r14 r13 ASR 32", "al_r14_r13_ASR_32"},
     {{al, r7, r8, ASR, 9}, "", "al r7 r8 ASR 9", "al_r7_r8_ASR_9"},
     {{al, r4, r8, ASR, 5}, "", "al r4 r8 ASR 5", "al_r4_r8_ASR_5"},
     {{al, r3, r9, LSR, 30}, "", "al r3 r9 LSR 30", "al_r3_r9_LSR_30"},
     {{al, r3, r12, ASR, 12}, "", "al r3 r12 ASR 12", "al_r3_r12_ASR_12"},
     {{al, r8, r6, ASR, 15}, "", "al r8 r6 ASR 15", "al_r8_r6_ASR_15"},
     {{al, r8, r13, ASR, 25}, "", "al r8 r13 ASR 25", "al_r8_r13_ASR_25"},
     {{al, r3, r10, LSR, 28}, "", "al r3 r10 LSR 28", "al_r3_r10_LSR_28"},
     {{al, r1, r14, LSR, 30}, "", "al r1 r14 LSR 30", "al_r1_r14_LSR_30"},
     {{al, r4, r9, ASR, 22}, "", "al r4 r9 ASR 22", "al_r4_r9_ASR_22"},
     {{al, r2, r13, LSR, 15}, "", "al r2 r13 LSR 15", "al_r2_r13_LSR_15"},
     {{al, r10, r0, ASR, 4}, "", "al r10 r0 ASR 4", "al_r10_r0_ASR_4"},
     {{al, r11, r12, ASR, 4}, "", "al r11 r12 ASR 4", "al_r11_r12_ASR_4"},
     {{al, r6, r9, LSR, 4}, "", "al r6 r9 LSR 4", "al_r6_r9_LSR_4"},
     {{al, r0, r3, ASR, 18}, "", "al r0 r3 ASR 18", "al_r0_r3_ASR_18"},
     {{al, r9, r4, ASR, 24}, "", "al r9 r4 ASR 24", "al_r9_r4_ASR_24"},
     {{al, r7, r3, LSR, 15}, "", "al r7 r3 LSR 15", "al_r7_r3_LSR_15"},
     {{al, r6, r4, LSR, 20}, "", "al r6 r4 LSR 20", "al_r6_r4_LSR_20"},
     {{al, r3, r9, ASR, 19}, "", "al r3 r9 ASR 19", "al_r3_r9_ASR_19"},
     {{al, r5, r14, LSR, 12}, "", "al r5 r14 LSR 12", "al_r5_r14_LSR_12"},
     {{al, r7, r12, LSR, 6}, "", "al r7 r12 LSR 6", "al_r7_r12_LSR_6"},
     {{al, r10, r5, LSR, 14}, "", "al r10 r5 LSR 14", "al_r10_r5_LSR_14"},
     {{al, r13, r9, LSR, 26}, "", "al r13 r9 LSR 26", "al_r13_r9_LSR_26"},
     {{al, r0, r6, LSR, 29}, "", "al r0 r6 LSR 29", "al_r0_r6_LSR_29"},
     {{al, r9, r11, ASR, 7}, "", "al r9 r11 ASR 7", "al_r9_r11_ASR_7"},
     {{al, r14, r14, LSR, 1}, "", "al r14 r14 LSR 1", "al_r14_r14_LSR_1"},
     {{al, r6, r3, ASR, 7}, "", "al r6 r3 ASR 7", "al_r6_r3_ASR_7"},
     {{al, r4, r8, ASR, 30}, "", "al r4 r8 ASR 30", "al_r4_r8_ASR_30"},
     {{al, r2, r9, LSR, 29}, "", "al r2 r9 LSR 29", "al_r2_r9_LSR_29"},
     {{al, r11, r3, LSR, 23}, "", "al r11 r3 LSR 23", "al_r11_r3_LSR_23"},
     {{al, r12, r3, ASR, 20}, "", "al r12 r3 ASR 20", "al_r12_r3_ASR_20"},
     {{al, r10, r5, LSR, 30}, "", "al r10 r5 LSR 30", "al_r10_r5_LSR_30"},
     {{al, r9, r10, ASR, 25}, "", "al r9 r10 ASR 25", "al_r9_r10_ASR_25"},
     {{al, r13, r9, LSR, 10}, "", "al r13 r9 LSR 10", "al_r13_r9_LSR_10"},
     {{al, r6, r4, ASR, 28}, "", "al r6 r4 ASR 28", "al_r6_r4_ASR_28"},
     {{al, r8, r6, ASR, 10}, "", "al r8 r6 ASR 10", "al_r8_r6_ASR_10"},
     {{al, r2, r11, LSR, 23}, "", "al r2 r11 LSR 23", "al_r2_r11_LSR_23"},
     {{al, r14, r7, ASR, 22}, "", "al r14 r7 ASR 22", "al_r14_r7_ASR_22"},
     {{al, r5, r3, ASR, 23}, "", "al r5 r3 ASR 23", "al_r5_r3_ASR_23"},
     {{al, r9, r4, LSR, 13}, "", "al r9 r4 LSR 13", "al_r9_r4_LSR_13"},
     {{al, r3, r10, ASR, 9}, "", "al r3 r10 ASR 9", "al_r3_r10_ASR_9"},
     {{al, r6, r6, ASR, 1}, "", "al r6 r6 ASR 1", "al_r6_r6_ASR_1"},
     {{al, r3, r11, ASR, 13}, "", "al r3 r11 ASR 13", "al_r3_r11_ASR_13"},
     {{al, r6, r9, LSR, 10}, "", "al r6 r9 LSR 10", "al_r6_r9_LSR_10"},
     {{al, r1, r5, ASR, 6}, "", "al r1 r5 ASR 6", "al_r1_r5_ASR_6"},
     {{al, r13, r0, ASR, 12}, "", "al r13 r0 ASR 12", "al_r13_r0_ASR_12"},
     {{al, r10, r10, ASR, 20}, "", "al r10 r10 ASR 20", "al_r10_r10_ASR_20"},
     {{al, r2, r3, LSR, 12}, "", "al r2 r3 LSR 12", "al_r2_r3_LSR_12"},
     {{al, r3, r1, ASR, 20}, "", "al r3 r1 ASR 20", "al_r3_r1_ASR_20"},
     {{al, r5, r6, LSR, 8}, "", "al r5 r6 LSR 8", "al_r5_r6_LSR_8"},
     {{al, r2, r13, ASR, 28}, "", "al r2 r13 ASR 28", "al_r2_r13_ASR_28"},
     {{al, r6, r14, LSR, 26}, "", "al r6 r14 LSR 26", "al_r6_r14_LSR_26"},
     {{al, r2, r4, LSR, 7}, "", "al r2 r4 LSR 7", "al_r2_r4_LSR_7"},
     {{al, r2, r13, LSR, 8}, "", "al r2 r13 LSR 8", "al_r2_r13_LSR_8"},
     {{al, r5, r6, ASR, 9}, "", "al r5 r6 ASR 9", "al_r5_r6_ASR_9"},
     {{al, r1, r12, ASR, 20}, "", "al r1 r12 ASR 20", "al_r1_r12_ASR_20"},
     {{al, r1, r8, LSR, 15}, "", "al r1 r8 LSR 15", "al_r1_r8_LSR_15"},
     {{al, r14, r5, ASR, 26}, "", "al r14 r5 ASR 26", "al_r14_r5_ASR_26"},
     {{al, r14, r3, LSR, 23}, "", "al r14 r3 LSR 23", "al_r14_r3_LSR_23"},
     {{al, r1, r0, ASR, 15}, "", "al r1 r0 ASR 15", "al_r1_r0_ASR_15"},
     {{al, r4, r2, LSR, 7}, "", "al r4 r2 LSR 7", "al_r4_r2_LSR_7"},
     {{al, r11, r13, LSR, 27}, "", "al r11 r13 LSR 27", "al_r11_r13_LSR_27"},
     {{al, r8, r1, LSR, 15}, "", "al r8 r1 LSR 15", "al_r8_r1_LSR_15"},
     {{al, r5, r10, ASR, 8}, "", "al r5 r10 ASR 8", "al_r5_r10_ASR_8"},
     {{al, r8, r9, ASR, 23}, "", "al r8 r9 ASR 23", "al_r8_r9_ASR_23"},
     {{al, r9, r6, LSR, 12}, "", "al r9 r6 LSR 12", "al_r9_r6_LSR_12"},
     {{al, r9, r1, LSR, 28}, "", "al r9 r1 LSR 28", "al_r9_r1_LSR_28"},
     {{al, r3, r0, LSR, 19}, "", "al r3 r0 LSR 19", "al_r3_r0_LSR_19"},
     {{al, r13, r2, LSR, 3}, "", "al r13 r2 LSR 3", "al_r13_r2_LSR_3"},
     {{al, r11, r11, LSR, 11}, "", "al r11 r11 LSR 11", "al_r11_r11_LSR_11"},
     {{al, r2, r13, LSR, 32}, "", "al r2 r13 LSR 32", "al_r2_r13_LSR_32"},
     {{al, r9, r5, ASR, 11}, "", "al r9 r5 ASR 11", "al_r9_r5_ASR_11"},
     {{al, r14, r11, ASR, 19}, "", "al r14 r11 ASR 19", "al_r14_r11_ASR_19"},
     {{al, r1, r3, LSR, 22}, "", "al r1 r3 LSR 22", "al_r1_r3_LSR_22"},
     {{al, r9, r10, ASR, 7}, "", "al r9 r10 ASR 7", "al_r9_r10_ASR_7"},
     {{al, r9, r0, LSR, 1}, "", "al r9 r0 LSR 1", "al_r9_r0_LSR_1"},
     {{al, r1, r8, LSR, 3}, "", "al r1 r8 LSR 3", "al_r1_r8_LSR_3"},
     {{al, r12, r4, ASR, 16}, "", "al r12 r4 ASR 16", "al_r12_r4_ASR_16"},
     {{al, r14, r10, LSR, 27}, "", "al r14 r10 LSR 27", "al_r14_r10_LSR_27"},
     {{al, r13, r5, ASR, 16}, "", "al r13 r5 ASR 16", "al_r13_r5_ASR_16"},
     {{al, r5, r11, LSR, 13}, "", "al r5 r11 LSR 13", "al_r5_r11_LSR_13"},
     {{al, r8, r8, ASR, 13}, "", "al r8 r8 ASR 13", "al_r8_r8_ASR_13"},
     {{al, r11, r14, LSR, 19}, "", "al r11 r14 LSR 19", "al_r11_r14_LSR_19"},
     {{al, r14, r4, LSR, 32}, "", "al r14 r4 LSR 32", "al_r14_r4_LSR_32"},
     {{al, r1, r7, LSR, 9}, "", "al r1 r7 LSR 9", "al_r1_r7_LSR_9"},
     {{al, r4, r13, LSR, 10}, "", "al r4 r13 LSR 10", "al_r4_r13_LSR_10"},
     {{al, r4, r13, LSR, 7}, "", "al r4 r13 LSR 7", "al_r4_r13_LSR_7"},
     {{al, r0, r8, LSR, 10}, "", "al r0 r8 LSR 10", "al_r0_r8_LSR_10"},
     {{al, r4, r14, LSR, 9}, "", "al r4 r14 LSR 9", "al_r4_r14_LSR_9"},
     {{al, r3, r9, ASR, 14}, "", "al r3 r9 ASR 14", "al_r3_r9_ASR_14"},
     {{al, r8, r2, LSR, 31}, "", "al r8 r2 LSR 31", "al_r8_r2_LSR_31"},
     {{al, r1, r14, ASR, 9}, "", "al r1 r14 ASR 9", "al_r1_r14_ASR_9"},
     {{al, r10, r3, ASR, 31}, "", "al r10 r3 ASR 31", "al_r10_r3_ASR_31"},
     {{al, r5, r6, LSR, 9}, "", "al r5 r6 LSR 9", "al_r5_r6_LSR_9"},
     {{al, r0, r0, LSR, 15}, "", "al r0 r0 LSR 15", "al_r0_r0_LSR_15"},
     {{al, r14, r7, LSR, 16}, "", "al r14 r7 LSR 16", "al_r14_r7_LSR_16"},
     {{al, r12, r0, ASR, 23}, "", "al r12 r0 ASR 23", "al_r12_r0_ASR_23"},
     {{al, r10, r3, ASR, 30}, "", "al r10 r3 ASR 30", "al_r10_r3_ASR_30"},
     {{al, r13, r13, LSR, 21}, "", "al r13 r13 LSR 21", "al_r13_r13_LSR_21"},
     {{al, r7, r1, LSR, 27}, "", "al r7 r1 LSR 27", "al_r7_r1_LSR_27"},
     {{al, r10, r9, ASR, 27}, "", "al r10 r9 ASR 27", "al_r10_r9_ASR_27"},
     {{al, r11, r11, LSR, 19}, "", "al r11 r11 LSR 19", "al_r11_r11_LSR_19"},
     {{al, r3, r1, LSR, 25}, "", "al r3 r1 LSR 25", "al_r3_r1_LSR_25"},
     {{al, r0, r5, ASR, 5}, "", "al r0 r5 ASR 5", "al_r0_r5_ASR_5"},
     {{al, r4, r11, ASR, 32}, "", "al r4 r11 ASR 32", "al_r4_r11_ASR_32"},
     {{al, r2, r7, ASR, 8}, "", "al r2 r7 ASR 8", "al_r2_r7_ASR_8"},
     {{al, r4, r13, LSR, 18}, "", "al r4 r13 LSR 18", "al_r4_r13_LSR_18"},
     {{al, r8, r10, LSR, 31}, "", "al r8 r10 LSR 31", "al_r8_r10_LSR_31"},
     {{al, r10, r3, LSR, 21}, "", "al r10 r3 LSR 21", "al_r10_r3_LSR_21"},
     {{al, r3, r5, LSR, 23}, "", "al r3 r5 LSR 23", "al_r3_r5_LSR_23"},
     {{al, r8, r9, ASR, 15}, "", "al r8 r9 ASR 15", "al_r8_r9_ASR_15"},
     {{al, r11, r11, LSR, 9}, "", "al r11 r11 LSR 9", "al_r11_r11_LSR_9"},
     {{al, r13, r13, ASR, 25}, "", "al r13 r13 ASR 25", "al_r13_r13_ASR_25"},
     {{al, r6, r13, ASR, 24}, "", "al r6 r13 ASR 24", "al_r6_r13_ASR_24"},
     {{al, r8, r2, LSR, 4}, "", "al r8 r2 LSR 4", "al_r8_r2_LSR_4"},
     {{al, r0, r10, ASR, 4}, "", "al r0 r10 ASR 4", "al_r0_r10_ASR_4"},
     {{al, r2, r1, LSR, 32}, "", "al r2 r1 LSR 32", "al_r2_r1_LSR_32"},
     {{al, r11, r10, LSR, 25}, "", "al r11 r10 LSR 25", "al_r11_r10_LSR_25"},
     {{al, r14, r13, LSR, 17}, "", "al r14 r13 LSR 17", "al_r14_r13_LSR_17"},
     {{al, r8, r4, ASR, 25}, "", "al r8 r4 ASR 25", "al_r8_r4_ASR_25"},
     {{al, r9, r0, ASR, 11}, "", "al r9 r0 ASR 11", "al_r9_r0_ASR_11"},
     {{al, r3, r2, ASR, 16}, "", "al r3 r2 ASR 16", "al_r3_r2_ASR_16"},
     {{al, r6, r3, ASR, 28}, "", "al r6 r3 ASR 28", "al_r6_r3_ASR_28"},
     {{al, r11, r8, LSR, 20}, "", "al r11 r8 LSR 20", "al_r11_r8_LSR_20"},
     {{al, r8, r13, ASR, 2}, "", "al r8 r13 ASR 2", "al_r8_r13_ASR_2"},
     {{al, r13, r6, LSR, 19}, "", "al r13 r6 LSR 19", "al_r13_r6_LSR_19"},
     {{al, r13, r10, ASR, 20}, "", "al r13 r10 ASR 20", "al_r13_r10_ASR_20"},
     {{al, r8, r7, LSR, 26}, "", "al r8 r7 LSR 26", "al_r8_r7_LSR_26"},
     {{al, r12, r4, LSR, 30}, "", "al r12 r4 LSR 30", "al_r12_r4_LSR_30"},
     {{al, r13, r6, LSR, 27}, "", "al r13 r6 LSR 27", "al_r13_r6_LSR_27"},
     {{al, r3, r3, LSR, 8}, "", "al r3 r3 LSR 8", "al_r3_r3_LSR_8"},
     {{al, r14, r1, ASR, 22}, "", "al r14 r1 ASR 22", "al_r14_r1_ASR_22"},
     {{al, r10, r10, LSR, 7}, "", "al r10 r10 LSR 7", "al_r10_r10_LSR_7"},
     {{al, r12, r0, ASR, 10}, "", "al r12 r0 ASR 10", "al_r12_r0_ASR_10"},
     {{al, r8, r4, ASR, 2}, "", "al r8 r4 ASR 2", "al_r8_r4_ASR_2"},
     {{al, r14, r14, LSR, 18}, "", "al r14 r14 LSR 18", "al_r14_r14_LSR_18"},
     {{al, r12, r5, LSR, 27}, "", "al r12 r5 LSR 27", "al_r12_r5_LSR_27"},
     {{al, r10, r8, LSR, 2}, "", "al r10 r8 LSR 2", "al_r10_r8_LSR_2"},
     {{al, r5, r4, LSR, 13}, "", "al r5 r4 LSR 13", "al_r5_r4_LSR_13"},
     {{al, r0, r12, LSR, 2}, "", "al r0 r12 LSR 2", "al_r0_r12_LSR_2"},
     {{al, r8, r6, LSR, 13}, "", "al r8 r6 LSR 13", "al_r8_r6_LSR_13"},
     {{al, r14, r4, LSR, 19}, "", "al r14 r4 LSR 19", "al_r14_r4_LSR_19"},
     {{al, r8, r1, LSR, 30}, "", "al r8 r1 LSR 30", "al_r8_r1_LSR_30"},
     {{al, r1, r1, LSR, 28}, "", "al r1 r1 LSR 28", "al_r1_r1_LSR_28"},
     {{al, r14, r1, ASR, 16}, "", "al r14 r1 ASR 16", "al_r14_r1_ASR_16"},
     {{al, r0, r11, LSR, 25}, "", "al r0 r11 LSR 25", "al_r0_r11_LSR_25"},
     {{al, r9, r11, LSR, 30}, "", "al r9 r11 LSR 30", "al_r9_r11_LSR_30"},
     {{al, r2, r10, ASR, 11}, "", "al r2 r10 ASR 11", "al_r2_r10_ASR_11"},
     {{al, r9, r11, LSR, 9}, "", "al r9 r11 LSR 9", "al_r9_r11_LSR_9"},
     {{al, r9, r12, LSR, 20}, "", "al r9 r12 LSR 20", "al_r9_r12_LSR_20"},
     {{al, r3, r1, ASR, 21}, "", "al r3 r1 ASR 21", "al_r3_r1_ASR_21"},
     {{al, r14, r14, ASR, 9}, "", "al r14 r14 ASR 9", "al_r14_r14_ASR_9"},
     {{al, r14, r13, LSR, 27}, "", "al r14 r13 LSR 27", "al_r14_r13_LSR_27"},
     {{al, r3, r3, LSR, 11}, "", "al r3 r3 LSR 11", "al_r3_r3_LSR_11"},
     {{al, r7, r3, LSR, 28}, "", "al r7 r3 LSR 28", "al_r7_r3_LSR_28"},
     {{al, r6, r14, ASR, 29}, "", "al r6 r14 ASR 29", "al_r6_r14_ASR_29"},
     {{al, r3, r12, ASR, 15}, "", "al r3 r12 ASR 15", "al_r3_r12_ASR_15"},
     {{al, r11, r12, LSR, 32}, "", "al r11 r12 LSR 32", "al_r11_r12_LSR_32"},
     {{al, r3, r8, LSR, 5}, "", "al r3 r8 LSR 5", "al_r3_r8_LSR_5"},
     {{al, r6, r12, LSR, 18}, "", "al r6 r12 LSR 18", "al_r6_r12_LSR_18"},
     {{al, r10, r6, LSR, 19}, "", "al r10 r6 LSR 19", "al_r10_r6_LSR_19"},
     {{al, r5, r7, LSR, 25}, "", "al r5 r7 LSR 25", "al_r5_r7_LSR_25"},
     {{al, r3, r13, LSR, 2}, "", "al r3 r13 LSR 2", "al_r3_r13_LSR_2"},
     {{al, r8, r3, ASR, 26}, "", "al r8 r3 ASR 26", "al_r8_r3_ASR_26"},
     {{al, r13, r3, LSR, 23}, "", "al r13 r3 LSR 23", "al_r13_r3_LSR_23"},
     {{al, r5, r2, LSR, 23}, "", "al r5 r2 LSR 23", "al_r5_r2_LSR_23"},
     {{al, r3, r12, ASR, 22}, "", "al r3 r12 ASR 22", "al_r3_r12_ASR_22"},
     {{al, r11, r10, ASR, 25}, "", "al r11 r10 ASR 25", "al_r11_r10_ASR_25"},
     {{al, r2, r11, LSR, 31}, "", "al r2 r11 LSR 31", "al_r2_r11_LSR_31"},
     {{al, r7, r8, LSR, 11}, "", "al r7 r8 LSR 11", "al_r7_r8_LSR_11"},
     {{al, r9, r14, ASR, 32}, "", "al r9 r14 ASR 32", "al_r9_r14_ASR_32"},
     {{al, r11, r14, ASR, 21}, "", "al r11 r14 ASR 21", "al_r11_r14_ASR_21"},
     {{al, r11, r13, ASR, 2}, "", "al r11 r13 ASR 2", "al_r11_r13_ASR_2"},
     {{al, r12, r3, ASR, 16}, "", "al r12 r3 ASR 16", "al_r12_r3_ASR_16"},
     {{al, r9, r11, ASR, 24}, "", "al r9 r11 ASR 24", "al_r9_r11_ASR_24"},
     {{al, r5, r7, LSR, 20}, "", "al r5 r7 LSR 20", "al_r5_r7_LSR_20"},
     {{al, r9, r4, ASR, 8}, "", "al r9 r4 ASR 8", "al_r9_r4_ASR_8"},
     {{al, r12, r9, ASR, 10}, "", "al r12 r9 ASR 10", "al_r12_r9_ASR_10"},
     {{al, r7, r10, LSR, 9}, "", "al r7 r10 LSR 9", "al_r7_r10_LSR_9"},
     {{al, r7, r4, LSR, 16}, "", "al r7 r4 LSR 16", "al_r7_r4_LSR_16"},
     {{al, r11, r5, LSR, 22}, "", "al r11 r5 LSR 22", "al_r11_r5_LSR_22"},
     {{al, r4, r8, LSR, 12}, "", "al r4 r8 LSR 12", "al_r4_r8_LSR_12"},
     {{al, r14, r7, ASR, 4}, "", "al r14 r7 ASR 4", "al_r14_r7_ASR_4"},
     {{al, r12, r13, LSR, 25}, "", "al r12 r13 LSR 25", "al_r12_r13_LSR_25"},
     {{al, r12, r5, LSR, 8}, "", "al r12 r5 LSR 8", "al_r12_r5_LSR_8"},
     {{al, r8, r11, LSR, 13}, "", "al r8 r11 LSR 13", "al_r8_r11_LSR_13"},
     {{al, r8, r11, ASR, 8}, "", "al r8 r11 ASR 8", "al_r8_r11_ASR_8"},
     {{al, r13, r13, LSR, 10}, "", "al r13 r13 LSR 10", "al_r13_r13_LSR_10"},
     {{al, r2, r4, ASR, 9}, "", "al r2 r4 ASR 9", "al_r2_r4_ASR_9"},
     {{al, r0, r5, ASR, 4}, "", "al r0 r5 ASR 4", "al_r0_r5_ASR_4"},
     {{al, r6, r0, LSR, 7}, "", "al r6 r0 LSR 7", "al_r6_r0_LSR_7"},
     {{al, r0, r2, ASR, 27}, "", "al r0 r2 ASR 27", "al_r0_r2_ASR_27"},
     {{al, r5, r9, ASR, 6}, "", "al r5 r9 ASR 6", "al_r5_r9_ASR_6"},
     {{al, r10, r10, ASR, 17}, "", "al r10 r10 ASR 17", "al_r10_r10_ASR_17"},
     {{al, r7, r9, ASR, 23}, "", "al r7 r9 ASR 23", "al_r7_r9_ASR_23"},
     {{al, r11, r11, LSR, 13}, "", "al r11 r11 LSR 13", "al_r11_r11_LSR_13"},
     {{al, r11, r4, ASR, 29}, "", "al r11 r4 ASR 29", "al_r11_r4_ASR_29"},
     {{al, r3, r3, LSR, 30}, "", "al r3 r3 LSR 30", "al_r3_r3_LSR_30"},
     {{al, r12, r11, ASR, 29}, "", "al r12 r11 ASR 29", "al_r12_r11_ASR_29"},
     {{al, r0, r9, ASR, 22}, "", "al r0 r9 ASR 22", "al_r0_r9_ASR_22"},
     {{al, r11, r5, ASR, 12}, "", "al r11 r5 ASR 12", "al_r11_r5_ASR_12"},
     {{al, r8, r9, ASR, 12}, "", "al r8 r9 ASR 12", "al_r8_r9_ASR_12"},
     {{al, r11, r0, LSR, 3}, "", "al r11 r0 LSR 3", "al_r11_r0_LSR_3"},
     {{al, r6, r13, LSR, 18}, "", "al r6 r13 LSR 18", "al_r6_r13_LSR_18"},
     {{al, r8, r10, ASR, 1}, "", "al r8 r10 ASR 1", "al_r8_r10_ASR_1"},
     {{al, r3, r2, LSR, 25}, "", "al r3 r2 LSR 25", "al_r3_r2_LSR_25"},
     {{al, r7, r6, ASR, 30}, "", "al r7 r6 ASR 30", "al_r7_r6_ASR_30"},
     {{al, r6, r2, LSR, 16}, "", "al r6 r2 LSR 16", "al_r6_r2_LSR_16"},
     {{al, r13, r8, ASR, 1}, "", "al r13 r8 ASR 1", "al_r13_r8_ASR_1"},
     {{al, r9, r12, LSR, 2}, "", "al r9 r12 LSR 2", "al_r9_r12_LSR_2"},
     {{al, r1, r7, LSR, 31}, "", "al r1 r7 LSR 31", "al_r1_r7_LSR_31"},
     {{al, r12, r13, ASR, 28}, "", "al r12 r13 ASR 28", "al_r12_r13_ASR_28"},
     {{al, r2, r11, LSR, 5}, "", "al r2 r11 LSR 5", "al_r2_r11_LSR_5"},
     {{al, r10, r2, LSR, 19}, "", "al r10 r2 LSR 19", "al_r10_r2_LSR_19"},
     {{al, r11, r2, LSR, 8}, "", "al r11 r2 LSR 8", "al_r11_r2_LSR_8"},
     {{al, r8, r8, LSR, 3}, "", "al r8 r8 LSR 3", "al_r8_r8_LSR_3"},
     {{al, r3, r3, LSR, 1}, "", "al r3 r3 LSR 1", "al_r3_r3_LSR_1"},
     {{al, r5, r4, LSR, 7}, "", "al r5 r4 LSR 7", "al_r5_r4_LSR_7"},
     {{al, r3, r2, ASR, 22}, "", "al r3 r2 ASR 22", "al_r3_r2_ASR_22"},
     {{al, r13, r14, LSR, 29}, "", "al r13 r14 LSR 29", "al_r13_r14_LSR_29"},
     {{al, r3, r8, LSR, 13}, "", "al r3 r8 LSR 13", "al_r3_r8_LSR_13"},
     {{al, r10, r11, LSR, 27}, "", "al r10 r11 LSR 27", "al_r10_r11_LSR_27"},
     {{al, r14, r3, LSR, 18}, "", "al r14 r3 LSR 18", "al_r14_r3_LSR_18"},
     {{al, r10, r0, ASR, 9}, "", "al r10 r0 ASR 9", "al_r10_r0_ASR_9"},
     {{al, r3, r1, ASR, 23}, "", "al r3 r1 ASR 23", "al_r3_r1_ASR_23"},
     {{al, r7, r10, LSR, 31}, "", "al r7 r10 LSR 31", "al_r7_r10_LSR_31"},
     {{al, r7, r7, LSR, 16}, "", "al r7 r7 LSR 16", "al_r7_r7_LSR_16"},
     {{al, r0, r10, ASR, 20}, "", "al r0 r10 ASR 20", "al_r0_r10_ASR_20"},
     {{al, r4, r14, LSR, 3}, "", "al r4 r14 LSR 3", "al_r4_r14_LSR_3"},
     {{al, r10, r12, LSR, 21}, "", "al r10 r12 LSR 21", "al_r10_r12_LSR_21"},
     {{al, r1, r10, ASR, 20}, "", "al r1 r10 ASR 20", "al_r1_r10_ASR_20"},
     {{al, r12, r5, ASR, 32}, "", "al r12 r5 ASR 32", "al_r12_r5_ASR_32"},
     {{al, r6, r3, LSR, 26}, "", "al r6 r3 LSR 26", "al_r6_r3_LSR_26"},
     {{al, r4, r12, ASR, 11}, "", "al r4 r12 ASR 11", "al_r4_r12_ASR_11"},
     {{al, r1, r7, LSR, 1}, "", "al r1 r7 LSR 1", "al_r1_r7_LSR_1"},
     {{al, r0, r3, LSR, 27}, "", "al r0 r3 LSR 27", "al_r0_r3_LSR_27"},
     {{al, r7, r9, LSR, 32}, "", "al r7 r9 LSR 32", "al_r7_r9_LSR_32"},
     {{al, r10, r1, LSR, 3}, "", "al r10 r1 LSR 3", "al_r10_r1_LSR_3"},
     {{al, r1, r11, LSR, 23}, "", "al r1 r11 LSR 23", "al_r1_r11_LSR_23"},
     {{al, r14, r6, ASR, 5}, "", "al r14 r6 ASR 5", "al_r14_r6_ASR_5"},
     {{al, r1, r12, LSR, 9}, "", "al r1 r12 LSR 9", "al_r1_r12_LSR_9"},
     {{al, r0, r1, LSR, 15}, "", "al r0 r1 LSR 15", "al_r0_r1_LSR_15"},
     {{al, r11, r2, ASR, 11}, "", "al r11 r2 ASR 11", "al_r11_r2_ASR_11"},
     {{al, r14, r14, ASR, 15}, "", "al r14 r14 ASR 15", "al_r14_r14_ASR_15"},
     {{al, r12, r4, LSR, 32}, "", "al r12 r4 LSR 32", "al_r12_r4_LSR_32"},
     {{al, r6, r6, ASR, 23}, "", "al r6 r6 ASR 23", "al_r6_r6_ASR_23"},
     {{al, r4, r10, ASR, 25}, "", "al r4 r10 ASR 25", "al_r4_r10_ASR_25"},
     {{al, r11, r10, LSR, 10}, "", "al r11 r10 LSR 10", "al_r11_r10_LSR_10"},
     {{al, r14, r4, LSR, 1}, "", "al r14 r4 LSR 1", "al_r14_r4_LSR_1"},
     {{al, r8, r11, LSR, 15}, "", "al r8 r11 LSR 15", "al_r8_r11_LSR_15"},
     {{al, r13, r8, ASR, 10}, "", "al r13 r8 ASR 10", "al_r13_r8_ASR_10"},
     {{al, r3, r0, LSR, 31}, "", "al r3 r0 LSR 31", "al_r3_r0_LSR_31"},
     {{al, r0, r14, LSR, 19}, "", "al r0 r14 LSR 19", "al_r0_r14_LSR_19"},
     {{al, r2, r14, ASR, 8}, "", "al r2 r14 ASR 8", "al_r2_r14_ASR_8"},
     {{al, r6, r5, LSR, 2}, "", "al r6 r5 LSR 2", "al_r6_r5_LSR_2"},
     {{al, r12, r10, ASR, 22}, "", "al r12 r10 ASR 22", "al_r12_r10_ASR_22"},
     {{al, r7, r0, LSR, 18}, "", "al r7 r0 LSR 18", "al_r7_r0_LSR_18"},
     {{al, r9, r13, ASR, 10}, "", "al r9 r13 ASR 10", "al_r9_r13_ASR_10"},
     {{al, r10, r13, ASR, 5}, "", "al r10 r13 ASR 5", "al_r10_r13_ASR_5"},
     {{al, r7, r2, ASR, 24}, "", "al r7 r2 ASR 24", "al_r7_r2_ASR_24"},
     {{al, r6, r5, LSR, 30}, "", "al r6 r5 LSR 30", "al_r6_r5_LSR_30"},
     {{al, r0, r11, ASR, 4}, "", "al r0 r11 ASR 4", "al_r0_r11_ASR_4"},
     {{al, r10, r8, ASR, 18}, "", "al r10 r8 ASR 18", "al_r10_r8_ASR_18"},
     {{al, r4, r11, LSR, 12}, "", "al r4 r11 LSR 12", "al_r4_r11_LSR_12"},
     {{al, r4, r7, ASR, 11}, "", "al r4 r7 ASR 11", "al_r4_r7_ASR_11"},
     {{al, r1, r10, LSR, 32}, "", "al r1 r10 LSR 32", "al_r1_r10_LSR_32"},
     {{al, r9, r11, ASR, 31}, "", "al r9 r11 ASR 31", "al_r9_r11_ASR_31"},
     {{al, r2, r6, ASR, 23}, "", "al r2 r6 ASR 23", "al_r2_r6_ASR_23"},
     {{al, r9, r14, LSR, 16}, "", "al r9 r14 LSR 16", "al_r9_r14_LSR_16"},
     {{al, r0, r14, ASR, 18}, "", "al r0 r14 ASR 18", "al_r0_r14_ASR_18"},
     {{al, r5, r6, LSR, 29}, "", "al r5 r6 LSR 29", "al_r5_r6_LSR_29"},
     {{al, r12, r9, LSR, 16}, "", "al r12 r9 LSR 16", "al_r12_r9_LSR_16"},
     {{al, r5, r9, LSR, 9}, "", "al r5 r9 LSR 9", "al_r5_r9_LSR_9"},
     {{al, r13, r9, LSR, 18}, "", "al r13 r9 LSR 18", "al_r13_r9_LSR_18"},
     {{al, r2, r11, ASR, 21}, "", "al r2 r11 ASR 21", "al_r2_r11_ASR_21"},
     {{al, r3, r2, LSR, 17}, "", "al r3 r2 LSR 17", "al_r3_r2_LSR_17"},
     {{al, r3, r13, ASR, 21}, "", "al r3 r13 ASR 21", "al_r3_r13_ASR_21"},
     {{al, r5, r2, LSR, 26}, "", "al r5 r2 LSR 26", "al_r5_r2_LSR_26"},
     {{al, r12, r1, LSR, 13}, "", "al r12 r1 LSR 13", "al_r12_r1_LSR_13"},
     {{al, r8, r7, ASR, 15}, "", "al r8 r7 ASR 15", "al_r8_r7_ASR_15"},
     {{al, r8, r1, LSR, 24}, "", "al r8 r1 LSR 24", "al_r8_r1_LSR_24"},
     {{al, r0, r12, ASR, 8}, "", "al r0 r12 ASR 8", "al_r0_r12_ASR_8"},
     {{al, r13, r10, ASR, 30}, "", "al r13 r10 ASR 30", "al_r13_r10_ASR_30"},
     {{al, r14, r10, ASR, 31}, "", "al r14 r10 ASR 31", "al_r14_r10_ASR_31"},
     {{al, r0, r0, LSR, 26}, "", "al r0 r0 LSR 26", "al_r0_r0_LSR_26"},
     {{al, r14, r4, ASR, 17}, "", "al r14 r4 ASR 17", "al_r14_r4_ASR_17"},
     {{al, r0, r13, LSR, 19}, "", "al r0 r13 LSR 19", "al_r0_r13_LSR_19"},
     {{al, r1, r9, ASR, 17}, "", "al r1 r9 ASR 17", "al_r1_r9_ASR_17"},
     {{al, r3, r11, ASR, 6}, "", "al r3 r11 ASR 6", "al_r3_r11_ASR_6"},
     {{al, r5, r1, LSR, 3}, "", "al r5 r1 LSR 3", "al_r5_r1_LSR_3"},
     {{al, r11, r3, LSR, 8}, "", "al r11 r3 LSR 8", "al_r11_r3_LSR_8"},
     {{al, r12, r3, LSR, 4}, "", "al r12 r3 LSR 4", "al_r12_r3_LSR_4"},
     {{al, r14, r5, ASR, 8}, "", "al r14 r5 ASR 8", "al_r14_r5_ASR_8"},
     {{al, r8, r7, LSR, 9}, "", "al r8 r7 LSR 9", "al_r8_r7_LSR_9"},
     {{al, r2, r2, ASR, 8}, "", "al r2 r2 ASR 8", "al_r2_r2_ASR_8"},
     {{al, r0, r14, ASR, 16}, "", "al r0 r14 ASR 16", "al_r0_r14_ASR_16"},
     {{al, r6, r14, LSR, 4}, "", "al r6 r14 LSR 4", "al_r6_r14_LSR_4"},
     {{al, r8, r5, ASR, 32}, "", "al r8 r5 ASR 32", "al_r8_r5_ASR_32"},
     {{al, r1, r14, LSR, 16}, "", "al r1 r14 LSR 16", "al_r1_r14_LSR_16"},
     {{al, r9, r11, LSR, 13}, "", "al r9 r11 LSR 13", "al_r9_r11_LSR_13"},
     {{al, r7, r6, ASR, 9}, "", "al r7 r6 ASR 9", "al_r7_r6_ASR_9"},
     {{al, r7, r6, ASR, 3}, "", "al r7 r6 ASR 3", "al_r7_r6_ASR_3"},
     {{al, r10, r3, LSR, 16}, "", "al r10 r3 LSR 16", "al_r10_r3_LSR_16"},
     {{al, r6, r4, ASR, 13}, "", "al r6 r4 ASR 13", "al_r6_r4_ASR_13"},
     {{al, r9, r7, ASR, 7}, "", "al r9 r7 ASR 7", "al_r9_r7_ASR_7"},
     {{al, r13, r12, LSR, 30}, "", "al r13 r12 LSR 30", "al_r13_r12_LSR_30"},
     {{al, r12, r9, LSR, 24}, "", "al r12 r9 LSR 24", "al_r12_r9_LSR_24"},
     {{al, r7, r2, ASR, 2}, "", "al r7 r2 ASR 2", "al_r7_r2_ASR_2"},
     {{al, r14, r12, ASR, 13}, "", "al r14 r12 ASR 13", "al_r14_r12_ASR_13"},
     {{al, r1, r5, LSR, 24}, "", "al r1 r5 LSR 24", "al_r1_r5_LSR_24"},
     {{al, r13, r2, ASR, 28}, "", "al r13 r2 ASR 28", "al_r13_r2_ASR_28"},
     {{al, r7, r5, LSR, 16}, "", "al r7 r5 LSR 16", "al_r7_r5_LSR_16"},
     {{al, r4, r0, ASR, 4}, "", "al r4 r0 ASR 4", "al_r4_r0_ASR_4"},
     {{al, r9, r9, ASR, 31}, "", "al r9 r9 ASR 31", "al_r9_r9_ASR_31"},
     {{al, r5, r5, ASR, 10}, "", "al r5 r5 ASR 10", "al_r5_r5_ASR_10"},
     {{al, r3, r8, ASR, 19}, "", "al r3 r8 ASR 19", "al_r3_r8_ASR_19"},
     {{al, r8, r12, ASR, 22}, "", "al r8 r12 ASR 22", "al_r8_r12_ASR_22"},
     {{al, r4, r10, LSR, 8}, "", "al r4 r10 LSR 8", "al_r4_r10_LSR_8"},
     {{al, r1, r11, LSR, 32}, "", "al r1 r11 LSR 32", "al_r1_r11_LSR_32"},
     {{al, r12, r13, LSR, 14}, "", "al r12 r13 LSR 14", "al_r12_r13_LSR_14"},
     {{al, r13, r0, LSR, 12}, "", "al r13 r0 LSR 12", "al_r13_r0_LSR_12"},
     {{al, r12, r1, LSR, 5}, "", "al r12 r1 LSR 5", "al_r12_r1_LSR_5"},
     {{al, r10, r8, ASR, 9}, "", "al r10 r8 ASR 9", "al_r10_r8_ASR_9"},
     {{al, r11, r2, LSR, 22}, "", "al r11 r2 LSR 22", "al_r11_r2_LSR_22"},
     {{al, r11, r3, ASR, 24}, "", "al r11 r3 ASR 24", "al_r11_r3_ASR_24"},
     {{al, r3, r11, ASR, 9}, "", "al r3 r11 ASR 9", "al_r3_r11_ASR_9"},
     {{al, r0, r7, LSR, 20}, "", "al r0 r7 LSR 20", "al_r0_r7_LSR_20"},
     {{al, r13, r11, LSR, 19}, "", "al r13 r11 LSR 19", "al_r13_r11_LSR_19"},
     {{al, r9, r3, LSR, 19}, "", "al r9 r3 LSR 19", "al_r9_r3_LSR_19"},
     {{al, r8, r12, LSR, 13}, "", "al r8 r12 LSR 13", "al_r8_r12_LSR_13"},
     {{al, r9, r4, ASR, 10}, "", "al r9 r4 ASR 10", "al_r9_r4_ASR_10"},
     {{al, r10, r6, LSR, 22}, "", "al r10 r6 LSR 22", "al_r10_r6_LSR_22"},
     {{al, r1, r14, ASR, 3}, "", "al r1 r14 ASR 3", "al_r1_r14_ASR_3"},
     {{al, r0, r11, LSR, 15}, "", "al r0 r11 LSR 15", "al_r0_r11_LSR_15"},
     {{al, r7, r14, LSR, 9}, "", "al r7 r14 LSR 9", "al_r7_r14_LSR_9"},
     {{al, r14, r7, ASR, 5}, "", "al r14 r7 ASR 5", "al_r14_r7_ASR_5"},
     {{al, r5, r0, ASR, 20}, "", "al r5 r0 ASR 20", "al_r5_r0_ASR_20"},
     {{al, r3, r3, ASR, 3}, "", "al r3 r3 ASR 3", "al_r3_r3_ASR_3"},
     {{al, r12, r13, ASR, 19}, "", "al r12 r13 ASR 19", "al_r12_r13_ASR_19"},
     {{al, r3, r10, LSR, 15}, "", "al r3 r10 LSR 15", "al_r3_r10_LSR_15"},
     {{al, r0, r4, LSR, 30}, "", "al r0 r4 LSR 30", "al_r0_r4_LSR_30"},
     {{al, r4, r12, ASR, 32}, "", "al r4 r12 ASR 32", "al_r4_r12_ASR_32"},
     {{al, r7, r13, ASR, 14}, "", "al r7 r13 ASR 14", "al_r7_r13_ASR_14"},
     {{al, r13, r8, LSR, 2}, "", "al r13 r8 LSR 2", "al_r13_r8_LSR_2"},
     {{al, r11, r1, LSR, 9}, "", "al r11 r1 LSR 9", "al_r11_r1_LSR_9"},
     {{al, r1, r12, LSR, 30}, "", "al r1 r12 LSR 30", "al_r1_r12_LSR_30"},
     {{al, r3, r4, ASR, 27}, "", "al r3 r4 ASR 27", "al_r3_r4_ASR_27"},
     {{al, r2, r0, LSR, 12}, "", "al r2 r0 LSR 12", "al_r2_r0_LSR_12"},
     {{al, r9, r14, ASR, 17}, "", "al r9 r14 ASR 17", "al_r9_r14_ASR_17"},
     {{al, r2, r0, LSR, 9}, "", "al r2 r0 LSR 9", "al_r2_r0_LSR_9"},
     {{al, r0, r3, ASR, 19}, "", "al r0 r3 ASR 19", "al_r0_r3_ASR_19"},
     {{al, r1, r8, LSR, 18}, "", "al r1 r8 LSR 18", "al_r1_r8_LSR_18"},
     {{al, r2, r2, ASR, 20}, "", "al r2 r2 ASR 20", "al_r2_r2_ASR_20"},
     {{al, r5, r9, LSR, 28}, "", "al r5 r9 LSR 28", "al_r5_r9_LSR_28"},
     {{al, r8, r14, ASR, 1}, "", "al r8 r14 ASR 1", "al_r8_r14_ASR_1"},
     {{al, r0, r12, ASR, 7}, "", "al r0 r12 ASR 7", "al_r0_r12_ASR_7"},
     {{al, r4, r13, ASR, 22}, "", "al r4 r13 ASR 22", "al_r4_r13_ASR_22"},
     {{al, r9, r3, LSR, 3}, "", "al r9 r3 LSR 3", "al_r9_r3_LSR_3"},
     {{al, r6, r7, ASR, 26}, "", "al r6 r7 ASR 26", "al_r6_r7_ASR_26"},
     {{al, r11, r7, LSR, 16}, "", "al r11 r7 LSR 16", "al_r11_r7_LSR_16"},
     {{al, r12, r1, LSR, 12}, "", "al r12 r1 LSR 12", "al_r12_r1_LSR_12"},
     {{al, r3, r4, LSR, 12}, "", "al r3 r4 LSR 12", "al_r3_r4_LSR_12"},
     {{al, r13, r9, LSR, 15}, "", "al r13 r9 LSR 15", "al_r13_r9_LSR_15"},
     {{al, r4, r5, LSR, 7}, "", "al r4 r5 LSR 7", "al_r4_r5_LSR_7"},
     {{al, r1, r13, ASR, 18}, "", "al r1 r13 ASR 18", "al_r1_r13_ASR_18"},
     {{al, r7, r8, LSR, 20}, "", "al r7 r8 LSR 20", "al_r7_r8_LSR_20"},
     {{al, r1, r4, LSR, 19}, "", "al r1 r4 LSR 19", "al_r1_r4_LSR_19"},
     {{al, r13, r5, LSR, 2}, "", "al r13 r5 LSR 2", "al_r13_r5_LSR_2"},
     {{al, r2, r9, LSR, 23}, "", "al r2 r9 LSR 23", "al_r2_r9_LSR_23"},
     {{al, r0, r0, LSR, 17}, "", "al r0 r0 LSR 17", "al_r0_r0_LSR_17"},
     {{al, r6, r7, LSR, 12}, "", "al r6 r7 LSR 12", "al_r6_r7_LSR_12"},
     {{al, r14, r10, ASR, 11}, "", "al r14 r10 ASR 11", "al_r14_r10_ASR_11"},
     {{al, r2, r10, LSR, 14}, "", "al r2 r10 LSR 14", "al_r2_r10_LSR_14"},
     {{al, r11, r1, LSR, 30}, "", "al r11 r1 LSR 30", "al_r11_r1_LSR_30"},
     {{al, r2, r8, ASR, 10}, "", "al r2 r8 ASR 10", "al_r2_r8_ASR_10"},
     {{al, r6, r10, ASR, 3}, "", "al r6 r10 ASR 3", "al_r6_r10_ASR_3"},
     {{al, r3, r4, LSR, 25}, "", "al r3 r4 LSR 25", "al_r3_r4_LSR_25"},
     {{al, r1, r1, ASR, 11}, "", "al r1 r1 ASR 11", "al_r1_r1_ASR_11"},
     {{al, r13, r6, LSR, 30}, "", "al r13 r6 LSR 30", "al_r13_r6_LSR_30"},
     {{al, r5, r6, ASR, 23}, "", "al r5 r6 ASR 23", "al_r5_r6_ASR_23"},
     {{al, r1, r6, LSR, 12}, "", "al r1 r6 LSR 12", "al_r1_r6_LSR_12"},
     {{al, r0, r0, LSR, 2}, "", "al r0 r0 LSR 2", "al_r0_r0_LSR_2"},
     {{al, r13, r13, ASR, 14}, "", "al r13 r13 ASR 14", "al_r13_r13_ASR_14"},
     {{al, r9, r12, ASR, 31}, "", "al r9 r12 ASR 31", "al_r9_r12_ASR_31"},
     {{al, r8, r6, ASR, 24}, "", "al r8 r6 ASR 24", "al_r8_r6_ASR_24"},
     {{al, r10, r5, ASR, 19}, "", "al r10 r5 ASR 19", "al_r10_r5_ASR_19"},
     {{al, r6, r13, LSR, 5}, "", "al r6 r13 LSR 5", "al_r6_r13_LSR_5"},
     {{al, r1, r0, LSR, 15}, "", "al r1 r0 LSR 15", "al_r1_r0_LSR_15"},
     {{al, r9, r2, LSR, 11}, "", "al r9 r2 LSR 11", "al_r9_r2_LSR_11"},
     {{al, r14, r0, ASR, 30}, "", "al r14 r0 ASR 30", "al_r14_r0_ASR_30"},
     {{al, r0, r1, ASR, 28}, "", "al r0 r1 ASR 28", "al_r0_r1_ASR_28"},
     {{al, r4, r7, ASR, 4}, "", "al r4 r7 ASR 4", "al_r4_r7_ASR_4"},
     {{al, r0, r13, ASR, 17}, "", "al r0 r13 ASR 17", "al_r0_r13_ASR_17"},
     {{al, r10, r1, LSR, 17}, "", "al r10 r1 LSR 17", "al_r10_r1_LSR_17"},
     {{al, r8, r6, LSR, 25}, "", "al r8 r6 LSR 25", "al_r8_r6_LSR_25"},
     {{al, r2, r6, ASR, 2}, "", "al r2 r6 ASR 2", "al_r2_r6_ASR_2"},
     {{al, r6, r12, ASR, 18}, "", "al r6 r12 ASR 18", "al_r6_r12_ASR_18"},
     {{al, r4, r7, ASR, 27}, "", "al r4 r7 ASR 27", "al_r4_r7_ASR_27"},
     {{al, r9, r12, LSR, 21}, "", "al r9 r12 LSR 21", "al_r9_r12_LSR_21"},
     {{al, r13, r9, ASR, 7}, "", "al r13 r9 ASR 7", "al_r13_r9_ASR_7"},
     {{al, r13, r0, ASR, 29}, "", "al r13 r0 ASR 29", "al_r13_r0_ASR_29"},
     {{al, r11, r4, ASR, 19}, "", "al r11 r4 ASR 19", "al_r11_r4_ASR_19"},
     {{al, r7, r9, ASR, 28}, "", "al r7 r9 ASR 28", "al_r7_r9_ASR_28"},
     {{al, r6, r7, LSR, 32}, "", "al r6 r7 LSR 32", "al_r6_r7_LSR_32"},
     {{al, r11, r13, ASR, 21}, "", "al r11 r13 ASR 21", "al_r11_r13_ASR_21"},
     {{al, r14, r6, LSR, 29}, "", "al r14 r6 LSR 29", "al_r14_r6_LSR_29"},
     {{al, r5, r13, LSR, 10}, "", "al r5 r13 LSR 10", "al_r5_r13_LSR_10"},
     {{al, r9, r4, ASR, 17}, "", "al r9 r4 ASR 17", "al_r9_r4_ASR_17"},
     {{al, r13, r4, ASR, 32}, "", "al r13 r4 ASR 32", "al_r13_r4_ASR_32"},
     {{al, r1, r12, ASR, 7}, "", "al r1 r12 ASR 7", "al_r1_r12_ASR_7"},
     {{al, r13, r1, LSR, 25}, "", "al r13 r1 LSR 25", "al_r13_r1_LSR_25"},
     {{al, r7, r0, ASR, 5}, "", "al r7 r0 ASR 5", "al_r7_r0_ASR_5"},
     {{al, r1, r13, ASR, 15}, "", "al r1 r13 ASR 15", "al_r1_r13_ASR_15"},
     {{al, r3, r14, ASR, 8}, "", "al r3 r14 ASR 8", "al_r3_r14_ASR_8"},
     {{al, r2, r14, LSR, 26}, "", "al r2 r14 LSR 26", "al_r2_r14_LSR_26"},
     {{al, r13, r9, ASR, 22}, "", "al r13 r9 ASR 22", "al_r13_r9_ASR_22"},
     {{al, r10, r3, LSR, 17}, "", "al r10 r3 LSR 17", "al_r10_r3_LSR_17"},
     {{al, r14, r7, LSR, 7}, "", "al r14 r7 LSR 7", "al_r14_r7_LSR_7"},
     {{al, r14, r13, LSR, 29}, "", "al r14 r13 LSR 29", "al_r14_r13_LSR_29"},
     {{al, r14, r0, ASR, 12}, "", "al r14 r0 ASR 12", "al_r14_r0_ASR_12"},
     {{al, r3, r3, ASR, 20}, "", "al r3 r3 ASR 20", "al_r3_r3_ASR_20"},
     {{al, r2, r7, ASR, 32}, "", "al r2 r7 ASR 32", "al_r2_r7_ASR_32"},
     {{al, r12, r13, LSR, 23}, "", "al r12 r13 LSR 23", "al_r12_r13_LSR_23"},
     {{al, r8, r3, ASR, 5}, "", "al r8 r3 ASR 5", "al_r8_r3_ASR_5"},
     {{al, r9, r0, LSR, 28}, "", "al r9 r0 LSR 28", "al_r9_r0_LSR_28"},
     {{al, r8, r13, LSR, 22}, "", "al r8 r13 LSR 22", "al_r8_r13_LSR_22"},
     {{al, r4, r3, LSR, 1}, "", "al r4 r3 LSR 1", "al_r4_r3_LSR_1"},
     {{al, r1, r2, ASR, 5}, "", "al r1 r2 ASR 5", "al_r1_r2_ASR_5"},
     {{al, r14, r1, LSR, 26}, "", "al r14 r1 LSR 26", "al_r14_r1_LSR_26"},
     {{al, r14, r11, ASR, 17}, "", "al r14 r11 ASR 17", "al_r14_r11_ASR_17"}};

// These headers each contain an array of `TestResult` with the reference output
// values. The reference arrays are names `kReference{mnemonic}`.
#include "aarch32/traces/assembler-cond-rd-operand-rn-shift-amount-1to32-t32-cmn.h"
#include "aarch32/traces/assembler-cond-rd-operand-rn-shift-amount-1to32-t32-cmp.h"
#include "aarch32/traces/assembler-cond-rd-operand-rn-shift-amount-1to32-t32-mov.h"
#include "aarch32/traces/assembler-cond-rd-operand-rn-shift-amount-1to32-t32-movs.h"
#include "aarch32/traces/assembler-cond-rd-operand-rn-shift-amount-1to32-t32-mvn.h"
#include "aarch32/traces/assembler-cond-rd-operand-rn-shift-amount-1to32-t32-mvns.h"
#include "aarch32/traces/assembler-cond-rd-operand-rn-shift-amount-1to32-t32-teq.h"
#include "aarch32/traces/assembler-cond-rd-operand-rn-shift-amount-1to32-t32-tst.h"


// The maximum number of errors to report in detail for each test.
static const unsigned kErrorReportLimit = 8;

typedef void (MacroAssembler::*Fn)(Condition cond,
                                   Register rd,
                                   const Operand& op);

static void TestHelper(Fn instruction,
                       const char* mnemonic,
                       const TestResult reference[]) {
  unsigned total_error_count = 0;
  MacroAssembler masm(BUF_SIZE);

  masm.UseT32();

  for (unsigned i = 0; i < ARRAY_SIZE(kTests); i++) {
    // Values to pass to the macro-assembler.
    Condition cond = kTests[i].operands.cond;
    Register rd = kTests[i].operands.rd;
    Register rn = kTests[i].operands.rn;
    ShiftType shift = kTests[i].operands.shift;
    uint32_t amount = kTests[i].operands.amount;
    Operand op(rn, shift, amount);

    uint32_t start = masm.GetCursorOffset();
    (masm.*instruction)(cond, rd, op);
    uint32_t end = masm.GetCursorOffset();

    const byte* result_ptr =
        masm.GetBuffer().GetOffsetAddress<const byte*>(start);
    uint32_t result_size = end - start;

    if (Test::generate_test_trace()) {
      // Print the result bytes.
      printf("static const byte kInstruction_%s_%s[] = {\n",
             mnemonic,
             kTests[i].identifier);
      for (uint32_t j = 0; j < result_size; j++) {
        if (j == 0) {
          printf("  0x%02" PRIx8, result_ptr[j]);
        } else {
          printf(", 0x%02" PRIx8, result_ptr[j]);
        }
      }
      // This comment is meant to be used by external tools to validate
      // the encoding. We can parse the comment to figure out what
      // instruction this corresponds to.
      printf(" // %s %s %s\n};\n",
             kTests[i].expect_instruction_before,
             mnemonic,
             kTests[i].operands_description);
    } else {
      // Check we've emitted the exact same encoding as present in the
      // trace file. Only print up to `kErrorReportLimit` errors.
      if (((result_size != reference[i].size) ||
           (memcmp(result_ptr, reference[i].encoding, reference[i].size) !=
            0)) &&
          (++total_error_count <= kErrorReportLimit)) {
        printf("Error when testing \"%s\" with operands \"%s\":\n",
               mnemonic,
               kTests[i].operands_description);
        printf("  Expected: ");
        for (uint32_t j = 0; j < reference[i].size; j++) {
          if (j == 0) {
            printf("0x%02" PRIx8, reference[i].encoding[j]);
          } else {
            printf(", 0x%02" PRIx8, reference[i].encoding[j]);
          }
        }
        printf("\n");
        printf("  Found:    ");
        for (uint32_t j = 0; j < result_size; j++) {
          if (j == 0) {
            printf("0x%02" PRIx8, result_ptr[j]);
          } else {
            printf(", 0x%02" PRIx8, result_ptr[j]);
          }
        }
        printf("\n");
      }
    }
  }

  masm.FinalizeCode();

  if (Test::generate_test_trace()) {
    // Finalize the trace file by writing the final `TestResult` array
    // which links all generated instruction encodings.
    printf("static const TestResult kReference%s[] = {\n", mnemonic);
    for (unsigned i = 0; i < ARRAY_SIZE(kTests); i++) {
      printf("  {\n");
      printf("    ARRAY_SIZE(kInstruction_%s_%s),\n",
             mnemonic,
             kTests[i].identifier);
      printf("    kInstruction_%s_%s,\n", mnemonic, kTests[i].identifier);
      printf("  },\n");
    }
    printf("};\n");
  } else {
    if (total_error_count > kErrorReportLimit) {
      printf("%u other errors follow.\n",
             total_error_count - kErrorReportLimit);
    }
  }
}

// Instantiate tests for each instruction in the list.
#define TEST(mnemonic)                                                      \
  static void Test_##mnemonic() {                                           \
    TestHelper(&MacroAssembler::mnemonic, #mnemonic, kReference##mnemonic); \
  }                                                                         \
  static Test test_##mnemonic(                                              \
      "AARCH32_ASSEMBLER_COND_RD_OPERAND_RN_SHIFT_AMOUNT_1TO32_"            \
      "T32_" #mnemonic,                                                     \
      &Test_##mnemonic);
FOREACH_INSTRUCTION(TEST)
#undef TEST

}  // aarch32
}  // vixl
