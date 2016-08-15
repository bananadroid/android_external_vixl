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
  M(Adc)                       \
  M(Adcs)                      \
  M(Add)                       \
  M(Adds)                      \
  M(And)                       \
  M(Ands)                      \
  M(Bic)                       \
  M(Bics)                      \
  M(Eor)                       \
  M(Eors)                      \
  M(Orr)                       \
  M(Orrs)                      \
  M(Rsb)                       \
  M(Rsbs)                      \
  M(Rsc)                       \
  M(Rscs)                      \
  M(Sbc)                       \
  M(Sbcs)                      \
  M(Sub)                       \
  M(Subs)


// Values to be passed to the assembler to produce the instruction under test.
struct Operands {
  Condition cond;
  Register rd;
  Register rn;
  uint32_t immediate;
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
static const TestData kTests[] = {
    {{le, r9, r4, 0x03fc0000}, "", "le r9 r4 0x03fc0000", "le_r9_r4_"
                                                          "0x03fc0000"},
    {{pl, r14, r3, 0x0003fc00},
     "",
     "pl r14 r3 0x0003fc00",
     "pl_r14_r3_0x0003fc00"},
    {{cc, r1, r6, 0x3fc00000}, "", "cc r1 r6 0x3fc00000", "cc_r1_r6_"
                                                          "0x3fc00000"},
    {{cc, r5, r1, 0x02ac0000}, "", "cc r5 r1 0x02ac0000", "cc_r5_r1_"
                                                          "0x02ac0000"},
    {{pl, r14, r4, 0xb000000a},
     "",
     "pl r14 r4 0xb000000a",
     "pl_r14_r4_0xb000000a"},
    {{cs, r2, r13, 0x0003fc00},
     "",
     "cs r2 r13 0x0003fc00",
     "cs_r2_r13_0x0003fc00"},
    {{mi, r13, r0, 0x2ac00000},
     "",
     "mi r13 r0 0x2ac00000",
     "mi_r13_r0_0x2ac00000"},
    {{vc, r0, r0, 0x000ff000}, "", "vc r0 r0 0x000ff000", "vc_r0_r0_"
                                                          "0x000ff000"},
    {{vs, r2, r9, 0x00000ff0}, "", "vs r2 r9 0x00000ff0", "vs_r2_r9_"
                                                          "0x00000ff0"},
    {{cc, r15, r7, 0x000000ff},
     "",
     "cc r15 r7 0x000000ff",
     "cc_r15_r7_0x000000ff"},
    {{ls, r4, r1, 0x0003fc00}, "", "ls r4 r1 0x0003fc00", "ls_r4_r1_"
                                                          "0x0003fc00"},
    {{gt, r13, r11, 0x3fc00000},
     "",
     "gt r13 r11 0x3fc00000",
     "gt_r13_r11_0x3fc00000"},
    {{hi, r3, r15, 0x2ac00000},
     "",
     "hi r3 r15 0x2ac00000",
     "hi_r3_r15_0x2ac00000"},
    {{ls, r7, r12, 0x02ac0000},
     "",
     "ls r7 r12 0x02ac0000",
     "ls_r7_r12_0x02ac0000"},
    {{cc, r10, r11, 0x00ab0000},
     "",
     "cc r10 r11 0x00ab0000",
     "cc_r10_r11_0x00ab0000"},
    {{mi, r3, r9, 0x03fc0000}, "", "mi r3 r9 0x03fc0000", "mi_r3_r9_"
                                                          "0x03fc0000"},
    {{gt, r8, r7, 0x000ff000}, "", "gt r8 r7 0x000ff000", "gt_r8_r7_"
                                                          "0x000ff000"},
    {{ls, r1, r2, 0x00ab0000}, "", "ls r1 r2 0x00ab0000", "ls_r1_r2_"
                                                          "0x00ab0000"},
    {{al, r12, r5, 0x00002ac0},
     "",
     "al r12 r5 0x00002ac0",
     "al_r12_r5_0x00002ac0"},
    {{eq, r15, r5, 0x000003fc},
     "",
     "eq r15 r5 0x000003fc",
     "eq_r15_r5_0x000003fc"},
    {{hi, r11, r9, 0x000000ab},
     "",
     "hi r11 r9 0x000000ab",
     "hi_r11_r9_0x000000ab"},
    {{cs, r10, r7, 0x00ab0000},
     "",
     "cs r10 r7 0x00ab0000",
     "cs_r10_r7_0x00ab0000"},
    {{gt, r3, r7, 0x02ac0000}, "", "gt r3 r7 0x02ac0000", "gt_r3_r7_"
                                                          "0x02ac0000"},
    {{le, r0, r0, 0x00ab0000}, "", "le r0 r0 0x00ab0000", "le_r0_r0_"
                                                          "0x00ab0000"},
    {{hi, r15, r4, 0x000000ab},
     "",
     "hi r15 r4 0x000000ab",
     "hi_r15_r4_0x000000ab"},
    {{cc, r4, r13, 0xab000000},
     "",
     "cc r4 r13 0xab000000",
     "cc_r4_r13_0xab000000"},
    {{al, r12, r2, 0x0ab00000},
     "",
     "al r12 r2 0x0ab00000",
     "al_r12_r2_0x0ab00000"},
    {{cc, r8, r1, 0x000ff000}, "", "cc r8 r1 0x000ff000", "cc_r8_r1_"
                                                          "0x000ff000"},
    {{le, r1, r1, 0x000ff000}, "", "le r1 r1 0x000ff000", "le_r1_r1_"
                                                          "0x000ff000"},
    {{gt, r3, r1, 0xff000000}, "", "gt r3 r1 0xff000000", "gt_r3_r1_"
                                                          "0xff000000"},
    {{ge, r4, r2, 0x3fc00000}, "", "ge r4 r2 0x3fc00000", "ge_r4_r2_"
                                                          "0x3fc00000"},
    {{cc, r8, r7, 0xac000002}, "", "cc r8 r7 0xac000002", "cc_r8_r7_"
                                                          "0xac000002"},
    {{vs, r9, r4, 0xb000000a}, "", "vs r9 r4 0xb000000a", "vs_r9_r4_"
                                                          "0xb000000a"},
    {{cs, r11, r5, 0x000000ab},
     "",
     "cs r11 r5 0x000000ab",
     "cs_r11_r5_0x000000ab"},
    {{eq, r4, r2, 0xb000000a}, "", "eq r4 r2 0xb000000a", "eq_r4_r2_"
                                                          "0xb000000a"},
    {{lt, r5, r14, 0x000000ab},
     "",
     "lt r5 r14 0x000000ab",
     "lt_r5_r14_0x000000ab"},
    {{cs, r2, r4, 0x0000ab00}, "", "cs r2 r4 0x0000ab00", "cs_r2_r4_"
                                                          "0x0000ab00"},
    {{hi, r5, r9, 0x003fc000}, "", "hi r5 r9 0x003fc000", "hi_r5_r9_"
                                                          "0x003fc000"},
    {{al, r0, r2, 0xb000000a}, "", "al r0 r2 0xb000000a", "al_r0_r2_"
                                                          "0xb000000a"},
    {{le, r13, r0, 0x0ff00000},
     "",
     "le r13 r0 0x0ff00000",
     "le_r13_r0_0x0ff00000"},
    {{eq, r9, r5, 0xb000000a}, "", "eq r9 r5 0xb000000a", "eq_r9_r5_"
                                                          "0xb000000a"},
    {{cc, r15, r8, 0x00ab0000},
     "",
     "cc r15 r8 0x00ab0000",
     "cc_r15_r8_0x00ab0000"},
    {{ge, r4, r3, 0x003fc000}, "", "ge r4 r3 0x003fc000", "ge_r4_r3_"
                                                          "0x003fc000"},
    {{hi, r15, r1, 0x000002ac},
     "",
     "hi r15 r1 0x000002ac",
     "hi_r15_r1_0x000002ac"},
    {{al, r10, r8, 0x000002ac},
     "",
     "al r10 r8 0x000002ac",
     "al_r10_r8_0x000002ac"},
    {{al, r3, r5, 0xc000003f}, "", "al r3 r5 0xc000003f", "al_r3_r5_"
                                                          "0xc000003f"},
    {{cc, r1, r8, 0x000000ff}, "", "cc r1 r8 0x000000ff", "cc_r1_r8_"
                                                          "0x000000ff"},
    {{vs, r8, r4, 0x003fc000}, "", "vs r8 r4 0x003fc000", "vs_r8_r4_"
                                                          "0x003fc000"},
    {{vc, r2, r2, 0x003fc000}, "", "vc r2 r2 0x003fc000", "vc_r2_r2_"
                                                          "0x003fc000"},
    {{hi, r1, r1, 0x03fc0000}, "", "hi r1 r1 0x03fc0000", "hi_r1_r1_"
                                                          "0x03fc0000"},
    {{cc, r6, r12, 0x00000000},
     "",
     "cc r6 r12 0x00000000",
     "cc_r6_r12_0x00000000"},
    {{hi, r8, r1, 0xc000002a}, "", "hi r8 r1 0xc000002a", "hi_r8_r1_"
                                                          "0xc000002a"},
    {{ge, r7, r12, 0x003fc000},
     "",
     "ge r7 r12 0x003fc000",
     "ge_r7_r12_0x003fc000"},
    {{gt, r1, r14, 0x02ac0000},
     "",
     "gt r1 r14 0x02ac0000",
     "gt_r1_r14_0x02ac0000"},
    {{eq, r4, r0, 0x0ff00000}, "", "eq r4 r0 0x0ff00000", "eq_r4_r0_"
                                                          "0x0ff00000"},
    {{vs, r6, r10, 0x00000ab0},
     "",
     "vs r6 r10 0x00000ab0",
     "vs_r6_r10_0x00000ab0"},
    {{eq, r4, r8, 0x03fc0000}, "", "eq r4 r8 0x03fc0000", "eq_r4_r8_"
                                                          "0x03fc0000"},
    {{lt, r8, r13, 0x002ac000},
     "",
     "lt r8 r13 0x002ac000",
     "lt_r8_r13_0x002ac000"},
    {{mi, r1, r5, 0x000003fc}, "", "mi r1 r5 0x000003fc", "mi_r1_r5_"
                                                          "0x000003fc"},
    {{ge, r8, r1, 0x00ab0000}, "", "ge r8 r1 0x00ab0000", "ge_r8_r1_"
                                                          "0x00ab0000"},
    {{al, r0, r8, 0xb000000a}, "", "al r0 r8 0xb000000a", "al_r0_r8_"
                                                          "0xb000000a"},
    {{cs, r3, r0, 0x0000ff00}, "", "cs r3 r0 0x0000ff00", "cs_r3_r0_"
                                                          "0x0000ff00"},
    {{le, r14, r6, 0x03fc0000},
     "",
     "le r14 r6 0x03fc0000",
     "le_r14_r6_0x03fc0000"},
    {{lt, r13, r7, 0xab000000},
     "",
     "lt r13 r7 0xab000000",
     "lt_r13_r7_0xab000000"},
    {{vc, r7, r7, 0x00ff0000}, "", "vc r7 r7 0x00ff0000", "vc_r7_r7_"
                                                          "0x00ff0000"},
    {{ls, r8, r1, 0x0ab00000}, "", "ls r8 r1 0x0ab00000", "ls_r8_r1_"
                                                          "0x0ab00000"},
    {{lt, r10, r12, 0x000002ac},
     "",
     "lt r10 r12 0x000002ac",
     "lt_r10_r12_0x000002ac"},
    {{ls, r11, r0, 0x3fc00000},
     "",
     "ls r11 r0 0x3fc00000",
     "ls_r11_r0_0x3fc00000"},
    {{ge, r9, r8, 0x002ac000}, "", "ge r9 r8 0x002ac000", "ge_r9_r8_"
                                                          "0x002ac000"},
    {{vc, r5, r2, 0x02ac0000}, "", "vc r5 r2 0x02ac0000", "vc_r5_r2_"
                                                          "0x02ac0000"},
    {{gt, r2, r9, 0x0ff00000}, "", "gt r2 r9 0x0ff00000", "gt_r2_r9_"
                                                          "0x0ff00000"},
    {{eq, r10, r6, 0x2ac00000},
     "",
     "eq r10 r6 0x2ac00000",
     "eq_r10_r6_0x2ac00000"},
    {{ls, r0, r9, 0xfc000003}, "", "ls r0 r9 0xfc000003", "ls_r0_r9_"
                                                          "0xfc000003"},
    {{eq, r15, r12, 0x02ac0000},
     "",
     "eq r15 r12 0x02ac0000",
     "eq_r15_r12_0x02ac0000"},
    {{mi, r3, r1, 0xfc000003}, "", "mi r3 r1 0xfc000003", "mi_r3_r1_"
                                                          "0xfc000003"},
    {{lt, r0, r0, 0xb000000a}, "", "lt r0 r0 0xb000000a", "lt_r0_r0_"
                                                          "0xb000000a"},
    {{cs, r14, r8, 0xff000000},
     "",
     "cs r14 r8 0xff000000",
     "cs_r14_r8_0xff000000"},
    {{lt, r7, r1, 0x00003fc0}, "", "lt r7 r1 0x00003fc0", "lt_r7_r1_"
                                                          "0x00003fc0"},
    {{ls, r8, r1, 0x00000ff0}, "", "ls r8 r1 0x00000ff0", "ls_r8_r1_"
                                                          "0x00000ff0"},
    {{cc, r15, r3, 0x0002ac00},
     "",
     "cc r15 r3 0x0002ac00",
     "cc_r15_r3_0x0002ac00"},
    {{cs, r15, r0, 0xc000003f},
     "",
     "cs r15 r0 0xc000003f",
     "cs_r15_r0_0xc000003f"},
    {{hi, r4, r2, 0x0002ac00}, "", "hi r4 r2 0x0002ac00", "hi_r4_r2_"
                                                          "0x0002ac00"},
    {{ne, r10, r12, 0x0003fc00},
     "",
     "ne r10 r12 0x0003fc00",
     "ne_r10_r12_0x0003fc00"},
    {{gt, r7, r13, 0x00003fc0},
     "",
     "gt r7 r13 0x00003fc0",
     "gt_r7_r13_0x00003fc0"},
    {{vc, r14, r4, 0xac000002},
     "",
     "vc r14 r4 0xac000002",
     "vc_r14_r4_0xac000002"},
    {{le, r13, r7, 0x00000000},
     "",
     "le r13 r7 0x00000000",
     "le_r13_r7_0x00000000"},
    {{pl, r5, r15, 0x00000ab0},
     "",
     "pl r5 r15 0x00000ab0",
     "pl_r5_r15_0x00000ab0"},
    {{vs, r1, r1, 0x03fc0000}, "", "vs r1 r1 0x03fc0000", "vs_r1_r1_"
                                                          "0x03fc0000"},
    {{le, r4, r4, 0xab000000}, "", "le r4 r4 0xab000000", "le_r4_r4_"
                                                          "0xab000000"},
    {{gt, r11, r4, 0x0ff00000},
     "",
     "gt r11 r4 0x0ff00000",
     "gt_r11_r4_0x0ff00000"},
    {{cc, r1, r3, 0x0000ab00}, "", "cc r1 r3 0x0000ab00", "cc_r1_r3_"
                                                          "0x0000ab00"},
    {{cs, r10, r9, 0x0000ab00},
     "",
     "cs r10 r9 0x0000ab00",
     "cs_r10_r9_0x0000ab00"},
    {{vc, r7, r5, 0x00ab0000}, "", "vc r7 r5 0x00ab0000", "vc_r7_r5_"
                                                          "0x00ab0000"},
    {{cc, r4, r1, 0x0000ab00}, "", "cc r4 r1 0x0000ab00", "cc_r4_r1_"
                                                          "0x0000ab00"},
    {{hi, r4, r15, 0xfc000003},
     "",
     "hi r4 r15 0xfc000003",
     "hi_r4_r15_0xfc000003"},
    {{eq, r11, r1, 0xff000000},
     "",
     "eq r11 r1 0xff000000",
     "eq_r11_r1_0xff000000"},
    {{gt, r4, r2, 0x00002ac0}, "", "gt r4 r2 0x00002ac0", "gt_r4_r2_"
                                                          "0x00002ac0"},
    {{ls, r10, r10, 0x000000ff},
     "",
     "ls r10 r10 0x000000ff",
     "ls_r10_r10_0x000000ff"},
    {{gt, r11, r10, 0x00ff0000},
     "",
     "gt r11 r10 0x00ff0000",
     "gt_r11_r10_0x00ff0000"},
    {{ls, r12, r6, 0x00000ff0},
     "",
     "ls r12 r6 0x00000ff0",
     "ls_r12_r6_0x00000ff0"},
    {{vc, r9, r4, 0xb000000a}, "", "vc r9 r4 0xb000000a", "vc_r9_r4_"
                                                          "0xb000000a"},
    {{hi, r10, r13, 0x00003fc0},
     "",
     "hi r10 r13 0x00003fc0",
     "hi_r10_r13_0x00003fc0"},
    {{vc, r6, r4, 0xab000000}, "", "vc r6 r4 0xab000000", "vc_r6_r4_"
                                                          "0xab000000"},
    {{gt, r1, r4, 0x0ff00000}, "", "gt r1 r4 0x0ff00000", "gt_r1_r4_"
                                                          "0x0ff00000"},
    {{ne, r8, r0, 0x00003fc0}, "", "ne r8 r0 0x00003fc0", "ne_r8_r0_"
                                                          "0x00003fc0"},
    {{ls, r13, r9, 0x0002ac00},
     "",
     "ls r13 r9 0x0002ac00",
     "ls_r13_r9_0x0002ac00"},
    {{eq, r8, r8, 0xfc000003}, "", "eq r8 r8 0xfc000003", "eq_r8_r8_"
                                                          "0xfc000003"},
    {{pl, r4, r3, 0x0002ac00}, "", "pl r4 r3 0x0002ac00", "pl_r4_r3_"
                                                          "0x0002ac00"},
    {{cc, r3, r1, 0xab000000}, "", "cc r3 r1 0xab000000", "cc_r3_r1_"
                                                          "0xab000000"},
    {{cc, r13, r3, 0xc000002a},
     "",
     "cc r13 r3 0xc000002a",
     "cc_r13_r3_0xc000002a"},
    {{cc, r10, r14, 0x00000000},
     "",
     "cc r10 r14 0x00000000",
     "cc_r10_r14_0x00000000"},
    {{hi, r13, r6, 0x000ff000},
     "",
     "hi r13 r6 0x000ff000",
     "hi_r13_r6_0x000ff000"},
    {{ge, r7, r15, 0x0002ac00},
     "",
     "ge r7 r15 0x0002ac00",
     "ge_r7_r15_0x0002ac00"},
    {{le, r1, r11, 0x0002ac00},
     "",
     "le r1 r11 0x0002ac00",
     "le_r1_r11_0x0002ac00"},
    {{gt, r12, r1, 0x02ac0000},
     "",
     "gt r12 r1 0x02ac0000",
     "gt_r12_r1_0x02ac0000"},
    {{hi, r0, r12, 0x00002ac0},
     "",
     "hi r0 r12 0x00002ac0",
     "hi_r0_r12_0x00002ac0"},
    {{lt, r6, r9, 0xfc000003}, "", "lt r6 r9 0xfc000003", "lt_r6_r9_"
                                                          "0xfc000003"},
    {{ls, r6, r6, 0x0002ac00}, "", "ls r6 r6 0x0002ac00", "ls_r6_r6_"
                                                          "0x0002ac00"},
    {{vc, r12, r3, 0xab000000},
     "",
     "vc r12 r3 0xab000000",
     "vc_r12_r3_0xab000000"},
    {{pl, r12, r10, 0x0ab00000},
     "",
     "pl r12 r10 0x0ab00000",
     "pl_r12_r10_0x0ab00000"},
    {{lt, r9, r11, 0xff000000},
     "",
     "lt r9 r11 0xff000000",
     "lt_r9_r11_0xff000000"},
    {{pl, r1, r11, 0x00000ff0},
     "",
     "pl r1 r11 0x00000ff0",
     "pl_r1_r11_0x00000ff0"},
    {{cs, r10, r3, 0x00003fc0},
     "",
     "cs r10 r3 0x00003fc0",
     "cs_r10_r3_0x00003fc0"},
    {{vs, r1, r12, 0x03fc0000},
     "",
     "vs r1 r12 0x03fc0000",
     "vs_r1_r12_0x03fc0000"},
    {{ls, r2, r2, 0xf000000f}, "", "ls r2 r2 0xf000000f", "ls_r2_r2_"
                                                          "0xf000000f"},
    {{pl, r11, r4, 0x0003fc00},
     "",
     "pl r11 r4 0x0003fc00",
     "pl_r11_r4_0x0003fc00"},
    {{cc, r13, r7, 0x03fc0000},
     "",
     "cc r13 r7 0x03fc0000",
     "cc_r13_r7_0x03fc0000"},
    {{hi, r5, r1, 0x00ab0000}, "", "hi r5 r1 0x00ab0000", "hi_r5_r1_"
                                                          "0x00ab0000"},
    {{eq, r8, r5, 0x0ab00000}, "", "eq r8 r5 0x0ab00000", "eq_r8_r5_"
                                                          "0x0ab00000"},
    {{ge, r6, r15, 0x0002ac00},
     "",
     "ge r6 r15 0x0002ac00",
     "ge_r6_r15_0x0002ac00"},
    {{ls, r5, r6, 0x00000ff0}, "", "ls r5 r6 0x00000ff0", "ls_r5_r6_"
                                                          "0x00000ff0"},
    {{gt, r13, r11, 0x000003fc},
     "",
     "gt r13 r11 0x000003fc",
     "gt_r13_r11_0x000003fc"},
    {{vc, r8, r6, 0xc000002a}, "", "vc r8 r6 0xc000002a", "vc_r8_r6_"
                                                          "0xc000002a"},
    {{ge, r10, r2, 0x000000ab},
     "",
     "ge r10 r2 0x000000ab",
     "ge_r10_r2_0x000000ab"},
    {{pl, r7, r14, 0x000000ab},
     "",
     "pl r7 r14 0x000000ab",
     "pl_r7_r14_0x000000ab"},
    {{vc, r11, r10, 0x3fc00000},
     "",
     "vc r11 r10 0x3fc00000",
     "vc_r11_r10_0x3fc00000"},
    {{pl, r9, r0, 0x00003fc0}, "", "pl r9 r0 0x00003fc0", "pl_r9_r0_"
                                                          "0x00003fc0"},
    {{hi, r15, r1, 0x000ab000},
     "",
     "hi r15 r1 0x000ab000",
     "hi_r15_r1_0x000ab000"},
    {{gt, r3, r4, 0x00ab0000}, "", "gt r3 r4 0x00ab0000", "gt_r3_r4_"
                                                          "0x00ab0000"},
    {{cs, r7, r12, 0x00000ab0},
     "",
     "cs r7 r12 0x00000ab0",
     "cs_r7_r12_0x00000ab0"},
    {{vs, r3, r8, 0x0ff00000}, "", "vs r3 r8 0x0ff00000", "vs_r3_r8_"
                                                          "0x0ff00000"},
    {{cc, r12, r8, 0x000000ff},
     "",
     "cc r12 r8 0x000000ff",
     "cc_r12_r8_0x000000ff"},
    {{vc, r1, r5, 0x02ac0000}, "", "vc r1 r5 0x02ac0000", "vc_r1_r5_"
                                                          "0x02ac0000"},
    {{cc, r7, r12, 0xf000000f},
     "",
     "cc r7 r12 0xf000000f",
     "cc_r7_r12_0xf000000f"},
    {{gt, r9, r4, 0x0000ab00}, "", "gt r9 r4 0x0000ab00", "gt_r9_r4_"
                                                          "0x0000ab00"},
    {{pl, r14, r8, 0x0ff00000},
     "",
     "pl r14 r8 0x0ff00000",
     "pl_r14_r8_0x0ff00000"},
    {{vc, r8, r4, 0x000003fc}, "", "vc r8 r4 0x000003fc", "vc_r8_r4_"
                                                          "0x000003fc"},
    {{cc, r1, r15, 0xb000000a},
     "",
     "cc r1 r15 0xb000000a",
     "cc_r1_r15_0xb000000a"},
    {{al, r15, r11, 0x000ff000},
     "",
     "al r15 r11 0x000ff000",
     "al_r15_r11_0x000ff000"},
    {{ls, r1, r13, 0x00002ac0},
     "",
     "ls r1 r13 0x00002ac0",
     "ls_r1_r13_0x00002ac0"},
    {{le, r4, r10, 0x03fc0000},
     "",
     "le r4 r10 0x03fc0000",
     "le_r4_r10_0x03fc0000"},
    {{mi, r2, r4, 0x00000ab0}, "", "mi r2 r4 0x00000ab0", "mi_r2_r4_"
                                                          "0x00000ab0"},
    {{al, r13, r6, 0x02ac0000},
     "",
     "al r13 r6 0x02ac0000",
     "al_r13_r6_0x02ac0000"},
    {{mi, r7, r9, 0x000002ac}, "", "mi r7 r9 0x000002ac", "mi_r7_r9_"
                                                          "0x000002ac"},
    {{hi, r9, r7, 0x00002ac0}, "", "hi r9 r7 0x00002ac0", "hi_r9_r7_"
                                                          "0x00002ac0"},
    {{vc, r15, r9, 0x0000ab00},
     "",
     "vc r15 r9 0x0000ab00",
     "vc_r15_r9_0x0000ab00"},
    {{vc, r13, r0, 0xff000000},
     "",
     "vc r13 r0 0xff000000",
     "vc_r13_r0_0xff000000"},
    {{cc, r15, r10, 0x00003fc0},
     "",
     "cc r15 r10 0x00003fc0",
     "cc_r15_r10_0x00003fc0"},
    {{lt, r12, r2, 0x00000ab0},
     "",
     "lt r12 r2 0x00000ab0",
     "lt_r12_r2_0x00000ab0"},
    {{le, r1, r3, 0xb000000a}, "", "le r1 r3 0xb000000a", "le_r1_r3_"
                                                          "0xb000000a"},
    {{hi, r14, r12, 0xc000002a},
     "",
     "hi r14 r12 0xc000002a",
     "hi_r14_r12_0xc000002a"},
    {{vc, r5, r8, 0x000ff000}, "", "vc r5 r8 0x000ff000", "vc_r5_r8_"
                                                          "0x000ff000"},
    {{gt, r12, r9, 0x000000ab},
     "",
     "gt r12 r9 0x000000ab",
     "gt_r12_r9_0x000000ab"},
    {{al, r13, r7, 0xf000000f},
     "",
     "al r13 r7 0xf000000f",
     "al_r13_r7_0xf000000f"},
    {{ls, r3, r10, 0x000002ac},
     "",
     "ls r3 r10 0x000002ac",
     "ls_r3_r10_0x000002ac"},
    {{ne, r13, r13, 0x00000ab0},
     "",
     "ne r13 r13 0x00000ab0",
     "ne_r13_r13_0x00000ab0"},
    {{ge, r15, r3, 0xfc000003},
     "",
     "ge r15 r3 0xfc000003",
     "ge_r15_r3_0xfc000003"},
    {{cc, r7, r0, 0x0003fc00}, "", "cc r7 r0 0x0003fc00", "cc_r7_r0_"
                                                          "0x0003fc00"},
    {{eq, r3, r14, 0x2ac00000},
     "",
     "eq r3 r14 0x2ac00000",
     "eq_r3_r14_0x2ac00000"},
    {{al, r11, r14, 0x003fc000},
     "",
     "al r11 r14 0x003fc000",
     "al_r11_r14_0x003fc000"},
    {{gt, r3, r12, 0x02ac0000},
     "",
     "gt r3 r12 0x02ac0000",
     "gt_r3_r12_0x02ac0000"},
    {{mi, r7, r15, 0xac000002},
     "",
     "mi r7 r15 0xac000002",
     "mi_r7_r15_0xac000002"},
    {{al, r3, r2, 0x002ac000}, "", "al r3 r2 0x002ac000", "al_r3_r2_"
                                                          "0x002ac000"},
    {{hi, r2, r6, 0x0002ac00}, "", "hi r2 r6 0x0002ac00", "hi_r2_r6_"
                                                          "0x0002ac00"},
    {{eq, r8, r5, 0x03fc0000}, "", "eq r8 r5 0x03fc0000", "eq_r8_r5_"
                                                          "0x03fc0000"},
    {{hi, r2, r13, 0x0002ac00},
     "",
     "hi r2 r13 0x0002ac00",
     "hi_r2_r13_0x0002ac00"},
    {{lt, r10, r10, 0x00ab0000},
     "",
     "lt r10 r10 0x00ab0000",
     "lt_r10_r10_0x00ab0000"},
    {{al, r12, r3, 0x0ab00000},
     "",
     "al r12 r3 0x0ab00000",
     "al_r12_r3_0x0ab00000"},
    {{ls, r1, r2, 0x003fc000}, "", "ls r1 r2 0x003fc000", "ls_r1_r2_"
                                                          "0x003fc000"},
    {{le, r9, r10, 0x000ff000},
     "",
     "le r9 r10 0x000ff000",
     "le_r9_r10_0x000ff000"},
    {{vc, r4, r12, 0x00000000},
     "",
     "vc r4 r12 0x00000000",
     "vc_r4_r12_0x00000000"},
    {{pl, r7, r7, 0x02ac0000}, "", "pl r7 r7 0x02ac0000", "pl_r7_r7_"
                                                          "0x02ac0000"},
    {{ge, r6, r11, 0x02ac0000},
     "",
     "ge r6 r11 0x02ac0000",
     "ge_r6_r11_0x02ac0000"},
    {{ls, r10, r4, 0x000000ff},
     "",
     "ls r10 r4 0x000000ff",
     "ls_r10_r4_0x000000ff"},
    {{cc, r12, r4, 0x00000ff0},
     "",
     "cc r12 r4 0x00000ff0",
     "cc_r12_r4_0x00000ff0"},
    {{gt, r6, r3, 0x0ff00000}, "", "gt r6 r3 0x0ff00000", "gt_r6_r3_"
                                                          "0x0ff00000"},
    {{cc, r3, r10, 0x00ab0000},
     "",
     "cc r3 r10 0x00ab0000",
     "cc_r3_r10_0x00ab0000"},
    {{eq, r6, r7, 0x00ab0000}, "", "eq r6 r7 0x00ab0000", "eq_r6_r7_"
                                                          "0x00ab0000"},
    {{le, r3, r3, 0x003fc000}, "", "le r3 r3 0x003fc000", "le_r3_r3_"
                                                          "0x003fc000"},
    {{lt, r11, r3, 0x3fc00000},
     "",
     "lt r11 r3 0x3fc00000",
     "lt_r11_r3_0x3fc00000"},
    {{vc, r11, r2, 0x00003fc0},
     "",
     "vc r11 r2 0x00003fc0",
     "vc_r11_r2_0x00003fc0"},
    {{ls, r11, r11, 0x000ff000},
     "",
     "ls r11 r11 0x000ff000",
     "ls_r11_r11_0x000ff000"},
    {{eq, r13, r2, 0x0000ff00},
     "",
     "eq r13 r2 0x0000ff00",
     "eq_r13_r2_0x0000ff00"},
    {{vc, r9, r1, 0x00002ac0}, "", "vc r9 r1 0x00002ac0", "vc_r9_r1_"
                                                          "0x00002ac0"},
    {{ne, r2, r14, 0xfc000003},
     "",
     "ne r2 r14 0xfc000003",
     "ne_r2_r14_0xfc000003"},
    {{vs, r10, r11, 0x00002ac0},
     "",
     "vs r10 r11 0x00002ac0",
     "vs_r10_r11_0x00002ac0"},
    {{cc, r9, r9, 0x000002ac}, "", "cc r9 r9 0x000002ac", "cc_r9_r9_"
                                                          "0x000002ac"},
    {{gt, r9, r3, 0x0000ab00}, "", "gt r9 r3 0x0000ab00", "gt_r9_r3_"
                                                          "0x0000ab00"},
    {{ge, r3, r0, 0x000000ab}, "", "ge r3 r0 0x000000ab", "ge_r3_r0_"
                                                          "0x000000ab"},
    {{pl, r6, r11, 0xb000000a},
     "",
     "pl r6 r11 0xb000000a",
     "pl_r6_r11_0xb000000a"},
    {{cs, r7, r3, 0xb000000a}, "", "cs r7 r3 0xb000000a", "cs_r7_r3_"
                                                          "0xb000000a"},
    {{ge, r0, r8, 0x00ff0000}, "", "ge r0 r8 0x00ff0000", "ge_r0_r8_"
                                                          "0x00ff0000"},
    {{lt, r9, r0, 0x00ab0000}, "", "lt r9 r0 0x00ab0000", "lt_r9_r0_"
                                                          "0x00ab0000"},
    {{cs, r8, r0, 0xc000003f}, "", "cs r8 r0 0xc000003f", "cs_r8_r0_"
                                                          "0xc000003f"},
    {{eq, r2, r5, 0x03fc0000}, "", "eq r2 r5 0x03fc0000", "eq_r2_r5_"
                                                          "0x03fc0000"},
    {{ls, r1, r9, 0x0000ab00}, "", "ls r1 r9 0x0000ab00", "ls_r1_r9_"
                                                          "0x0000ab00"},
    {{al, r3, r1, 0x00000ab0}, "", "al r3 r1 0x00000ab0", "al_r3_r1_"
                                                          "0x00000ab0"},
    {{gt, r11, r11, 0xfc000003},
     "",
     "gt r11 r11 0xfc000003",
     "gt_r11_r11_0xfc000003"},
    {{hi, r9, r8, 0x00000ab0}, "", "hi r9 r8 0x00000ab0", "hi_r9_r8_"
                                                          "0x00000ab0"},
    {{gt, r6, r10, 0xff000000},
     "",
     "gt r6 r10 0xff000000",
     "gt_r6_r10_0xff000000"},
    {{le, r9, r14, 0x00003fc0},
     "",
     "le r9 r14 0x00003fc0",
     "le_r9_r14_0x00003fc0"},
    {{cc, r11, r0, 0xf000000f},
     "",
     "cc r11 r0 0xf000000f",
     "cc_r11_r0_0xf000000f"},
    {{pl, r8, r5, 0x000002ac}, "", "pl r8 r5 0x000002ac", "pl_r8_r5_"
                                                          "0x000002ac"},
    {{gt, r1, r15, 0x000ff000},
     "",
     "gt r1 r15 0x000ff000",
     "gt_r1_r15_0x000ff000"},
    {{eq, r1, r2, 0x02ac0000}, "", "eq r1 r2 0x02ac0000", "eq_r1_r2_"
                                                          "0x02ac0000"},
    {{ge, r8, r7, 0x0ff00000}, "", "ge r8 r7 0x0ff00000", "ge_r8_r7_"
                                                          "0x0ff00000"},
    {{le, r15, r14, 0x0000ab00},
     "",
     "le r15 r14 0x0000ab00",
     "le_r15_r14_0x0000ab00"},
    {{al, r15, r11, 0x00002ac0},
     "",
     "al r15 r11 0x00002ac0",
     "al_r15_r11_0x00002ac0"},
    {{al, r11, r4, 0x000002ac},
     "",
     "al r11 r4 0x000002ac",
     "al_r11_r4_0x000002ac"},
    {{le, r13, r12, 0x000003fc},
     "",
     "le r13 r12 0x000003fc",
     "le_r13_r12_0x000003fc"},
    {{al, r15, r8, 0x000ff000},
     "",
     "al r15 r8 0x000ff000",
     "al_r15_r8_0x000ff000"},
    {{eq, r4, r2, 0x0002ac00}, "", "eq r4 r2 0x0002ac00", "eq_r4_r2_"
                                                          "0x0002ac00"},
    {{ge, r1, r9, 0x002ac000}, "", "ge r1 r9 0x002ac000", "ge_r1_r9_"
                                                          "0x002ac000"},
    {{lt, r12, r5, 0x00000000},
     "",
     "lt r12 r5 0x00000000",
     "lt_r12_r5_0x00000000"},
    {{pl, r10, r8, 0x00000ff0},
     "",
     "pl r10 r8 0x00000ff0",
     "pl_r10_r8_0x00000ff0"},
    {{ge, r13, r12, 0x00ff0000},
     "",
     "ge r13 r12 0x00ff0000",
     "ge_r13_r12_0x00ff0000"},
    {{al, r9, r7, 0x00000ff0}, "", "al r9 r7 0x00000ff0", "al_r9_r7_"
                                                          "0x00000ff0"},
    {{ls, r6, r3, 0x00000000}, "", "ls r6 r3 0x00000000", "ls_r6_r3_"
                                                          "0x00000000"},
    {{al, r1, r2, 0x00002ac0}, "", "al r1 r2 0x00002ac0", "al_r1_r2_"
                                                          "0x00002ac0"},
    {{le, r4, r12, 0x0002ac00},
     "",
     "le r4 r12 0x0002ac00",
     "le_r4_r12_0x0002ac00"},
    {{ge, r7, r1, 0x0000ff00}, "", "ge r7 r1 0x0000ff00", "ge_r7_r1_"
                                                          "0x0000ff00"},
    {{le, r10, r14, 0x3fc00000},
     "",
     "le r10 r14 0x3fc00000",
     "le_r10_r14_0x3fc00000"},
    {{al, r7, r9, 0x000000ab}, "", "al r7 r9 0x000000ab", "al_r7_r9_"
                                                          "0x000000ab"},
    {{hi, r6, r3, 0x000003fc}, "", "hi r6 r3 0x000003fc", "hi_r6_r3_"
                                                          "0x000003fc"},
    {{cs, r14, r11, 0x000000ff},
     "",
     "cs r14 r11 0x000000ff",
     "cs_r14_r11_0x000000ff"},
    {{le, r0, r15, 0xab000000},
     "",
     "le r0 r15 0xab000000",
     "le_r0_r15_0xab000000"},
    {{ls, r0, r3, 0xc000002a}, "", "ls r0 r3 0xc000002a", "ls_r0_r3_"
                                                          "0xc000002a"},
    {{le, r5, r6, 0x000002ac}, "", "le r5 r6 0x000002ac", "le_r5_r6_"
                                                          "0x000002ac"},
    {{eq, r5, r9, 0xb000000a}, "", "eq r5 r9 0xb000000a", "eq_r5_r9_"
                                                          "0xb000000a"},
    {{al, r12, r6, 0x000002ac},
     "",
     "al r12 r6 0x000002ac",
     "al_r12_r6_0x000002ac"},
    {{vs, r11, r10, 0x0003fc00},
     "",
     "vs r11 r10 0x0003fc00",
     "vs_r11_r10_0x0003fc00"},
    {{gt, r8, r5, 0x0003fc00}, "", "gt r8 r5 0x0003fc00", "gt_r8_r5_"
                                                          "0x0003fc00"},
    {{eq, r1, r9, 0x00000000}, "", "eq r1 r9 0x00000000", "eq_r1_r9_"
                                                          "0x00000000"},
    {{ge, r2, r9, 0x3fc00000}, "", "ge r2 r9 0x3fc00000", "ge_r2_r9_"
                                                          "0x3fc00000"},
    {{cs, r4, r13, 0x00ab0000},
     "",
     "cs r4 r13 0x00ab0000",
     "cs_r4_r13_0x00ab0000"},
    {{hi, r4, r12, 0x00ab0000},
     "",
     "hi r4 r12 0x00ab0000",
     "hi_r4_r12_0x00ab0000"},
    {{ne, r2, r3, 0x003fc000}, "", "ne r2 r3 0x003fc000", "ne_r2_r3_"
                                                          "0x003fc000"},
    {{vs, r0, r11, 0xfc000003},
     "",
     "vs r0 r11 0xfc000003",
     "vs_r0_r11_0xfc000003"},
    {{hi, r14, r9, 0x003fc000},
     "",
     "hi r14 r9 0x003fc000",
     "hi_r14_r9_0x003fc000"},
    {{vc, r7, r5, 0xab000000}, "", "vc r7 r5 0xab000000", "vc_r7_r5_"
                                                          "0xab000000"},
    {{lt, r15, r8, 0x002ac000},
     "",
     "lt r15 r8 0x002ac000",
     "lt_r15_r8_0x002ac000"},
    {{cs, r3, r7, 0x0003fc00}, "", "cs r3 r7 0x0003fc00", "cs_r3_r7_"
                                                          "0x0003fc00"},
    {{cs, r7, r11, 0xb000000a},
     "",
     "cs r7 r11 0xb000000a",
     "cs_r7_r11_0xb000000a"},
    {{ge, r0, r11, 0xb000000a},
     "",
     "ge r0 r11 0xb000000a",
     "ge_r0_r11_0xb000000a"},
    {{vs, r6, r5, 0x0ab00000}, "", "vs r6 r5 0x0ab00000", "vs_r6_r5_"
                                                          "0x0ab00000"},
    {{le, r10, r1, 0xfc000003},
     "",
     "le r10 r1 0xfc000003",
     "le_r10_r1_0xfc000003"},
    {{cc, r3, r6, 0x3fc00000}, "", "cc r3 r6 0x3fc00000", "cc_r3_r6_"
                                                          "0x3fc00000"},
    {{le, r12, r14, 0x00000ab0},
     "",
     "le r12 r14 0x00000ab0",
     "le_r12_r14_0x00000ab0"},
    {{al, r15, r12, 0x00003fc0},
     "",
     "al r15 r12 0x00003fc0",
     "al_r15_r12_0x00003fc0"},
    {{gt, r12, r10, 0x0000ab00},
     "",
     "gt r12 r10 0x0000ab00",
     "gt_r12_r10_0x0000ab00"},
    {{ls, r6, r15, 0x0ff00000},
     "",
     "ls r6 r15 0x0ff00000",
     "ls_r6_r15_0x0ff00000"},
    {{mi, r4, r4, 0x00003fc0}, "", "mi r4 r4 0x00003fc0", "mi_r4_r4_"
                                                          "0x00003fc0"},
    {{gt, r8, r9, 0xc000002a}, "", "gt r8 r9 0xc000002a", "gt_r8_r9_"
                                                          "0xc000002a"},
    {{le, r10, r4, 0x000002ac},
     "",
     "le r10 r4 0x000002ac",
     "le_r10_r4_0x000002ac"},
    {{vs, r0, r1, 0x000003fc}, "", "vs r0 r1 0x000003fc", "vs_r0_r1_"
                                                          "0x000003fc"},
    {{al, r1, r5, 0x0ff00000}, "", "al r1 r5 0x0ff00000", "al_r1_r5_"
                                                          "0x0ff00000"},
    {{cc, r11, r5, 0xc000002a},
     "",
     "cc r11 r5 0xc000002a",
     "cc_r11_r5_0xc000002a"},
    {{vc, r6, r13, 0x003fc000},
     "",
     "vc r6 r13 0x003fc000",
     "vc_r6_r13_0x003fc000"},
    {{eq, r1, r15, 0x00003fc0},
     "",
     "eq r1 r15 0x00003fc0",
     "eq_r1_r15_0x00003fc0"},
    {{lt, r15, r10, 0x000002ac},
     "",
     "lt r15 r10 0x000002ac",
     "lt_r15_r10_0x000002ac"},
    {{ne, r13, r13, 0x003fc000},
     "",
     "ne r13 r13 0x003fc000",
     "ne_r13_r13_0x003fc000"},
    {{mi, r11, r7, 0xc000002a},
     "",
     "mi r11 r7 0xc000002a",
     "mi_r11_r7_0xc000002a"},
    {{cc, r6, r2, 0x00ff0000}, "", "cc r6 r2 0x00ff0000", "cc_r6_r2_"
                                                          "0x00ff0000"},
    {{gt, r9, r1, 0x0000ab00}, "", "gt r9 r1 0x0000ab00", "gt_r9_r1_"
                                                          "0x0000ab00"},
    {{le, r11, r7, 0x000000ff},
     "",
     "le r11 r7 0x000000ff",
     "le_r11_r7_0x000000ff"},
    {{hi, r9, r8, 0x0002ac00}, "", "hi r9 r8 0x0002ac00", "hi_r9_r8_"
                                                          "0x0002ac00"},
    {{vs, r6, r8, 0xff000000}, "", "vs r6 r8 0xff000000", "vs_r6_r8_"
                                                          "0xff000000"},
    {{mi, r10, r4, 0x000ab000},
     "",
     "mi r10 r4 0x000ab000",
     "mi_r10_r4_0x000ab000"},
    {{ls, r7, r10, 0xab000000},
     "",
     "ls r7 r10 0xab000000",
     "ls_r7_r10_0xab000000"},
    {{lt, r1, r0, 0x00000000}, "", "lt r1 r0 0x00000000", "lt_r1_r0_"
                                                          "0x00000000"},
    {{eq, r2, r13, 0x00002ac0},
     "",
     "eq r2 r13 0x00002ac0",
     "eq_r2_r13_0x00002ac0"},
    {{cc, r14, r13, 0x00003fc0},
     "",
     "cc r14 r13 0x00003fc0",
     "cc_r14_r13_0x00003fc0"},
    {{le, r9, r4, 0x0ab00000}, "", "le r9 r4 0x0ab00000", "le_r9_r4_"
                                                          "0x0ab00000"},
    {{gt, r4, r7, 0x00000ab0}, "", "gt r4 r7 0x00000ab0", "gt_r4_r7_"
                                                          "0x00000ab0"},
    {{eq, r5, r4, 0xc000003f}, "", "eq r5 r4 0xc000003f", "eq_r5_r4_"
                                                          "0xc000003f"},
    {{al, r2, r13, 0xb000000a},
     "",
     "al r2 r13 0xb000000a",
     "al_r2_r13_0xb000000a"},
    {{le, r13, r11, 0x2ac00000},
     "",
     "le r13 r11 0x2ac00000",
     "le_r13_r11_0x2ac00000"},
    {{gt, r5, r14, 0xac000002},
     "",
     "gt r5 r14 0xac000002",
     "gt_r5_r14_0xac000002"},
    {{vs, r2, r7, 0x000000ab}, "", "vs r2 r7 0x000000ab", "vs_r2_r7_"
                                                          "0x000000ab"},
    {{ne, r6, r1, 0x0ab00000}, "", "ne r6 r1 0x0ab00000", "ne_r6_r1_"
                                                          "0x0ab00000"},
    {{eq, r4, r7, 0x0000ff00}, "", "eq r4 r7 0x0000ff00", "eq_r4_r7_"
                                                          "0x0000ff00"},
    {{cc, r11, r12, 0xc000003f},
     "",
     "cc r11 r12 0xc000003f",
     "cc_r11_r12_0xc000003f"},
    {{pl, r7, r9, 0x02ac0000}, "", "pl r7 r9 0x02ac0000", "pl_r7_r9_"
                                                          "0x02ac0000"},
    {{vc, r5, r4, 0x00000000}, "", "vc r5 r4 0x00000000", "vc_r5_r4_"
                                                          "0x00000000"},
    {{le, r7, r1, 0xc000002a}, "", "le r7 r1 0xc000002a", "le_r7_r1_"
                                                          "0xc000002a"},
    {{cs, r3, r10, 0x2ac00000},
     "",
     "cs r3 r10 0x2ac00000",
     "cs_r3_r10_0x2ac00000"},
    {{le, r11, r13, 0x00003fc0},
     "",
     "le r11 r13 0x00003fc0",
     "le_r11_r13_0x00003fc0"},
    {{pl, r2, r11, 0x000000ff},
     "",
     "pl r2 r11 0x000000ff",
     "pl_r2_r11_0x000000ff"},
    {{cs, r14, r11, 0x00000000},
     "",
     "cs r14 r11 0x00000000",
     "cs_r14_r11_0x00000000"},
    {{ls, r6, r8, 0x003fc000}, "", "ls r6 r8 0x003fc000", "ls_r6_r8_"
                                                          "0x003fc000"},
    {{al, r6, r8, 0xab000000}, "", "al r6 r8 0xab000000", "al_r6_r8_"
                                                          "0xab000000"},
    {{cc, r4, r2, 0x002ac000}, "", "cc r4 r2 0x002ac000", "cc_r4_r2_"
                                                          "0x002ac000"},
    {{lt, r3, r13, 0x003fc000},
     "",
     "lt r3 r13 0x003fc000",
     "lt_r3_r13_0x003fc000"},
    {{lt, r7, r3, 0x02ac0000}, "", "lt r7 r3 0x02ac0000", "lt_r7_r3_"
                                                          "0x02ac0000"},
    {{gt, r12, r1, 0x0000ff00},
     "",
     "gt r12 r1 0x0000ff00",
     "gt_r12_r1_0x0000ff00"},
    {{mi, r13, r11, 0x02ac0000},
     "",
     "mi r13 r11 0x02ac0000",
     "mi_r13_r11_0x02ac0000"},
    {{al, r9, r0, 0xc000003f}, "", "al r9 r0 0xc000003f", "al_r9_r0_"
                                                          "0xc000003f"},
    {{mi, r12, r9, 0x00003fc0},
     "",
     "mi r12 r9 0x00003fc0",
     "mi_r12_r9_0x00003fc0"},
    {{ge, r5, r2, 0x3fc00000}, "", "ge r5 r2 0x3fc00000", "ge_r5_r2_"
                                                          "0x3fc00000"},
    {{gt, r4, r2, 0x002ac000}, "", "gt r4 r2 0x002ac000", "gt_r4_r2_"
                                                          "0x002ac000"},
    {{cs, r6, r13, 0x00003fc0},
     "",
     "cs r6 r13 0x00003fc0",
     "cs_r6_r13_0x00003fc0"},
    {{ne, r14, r0, 0xff000000},
     "",
     "ne r14 r0 0xff000000",
     "ne_r14_r0_0xff000000"},
    {{ls, r5, r11, 0xc000002a},
     "",
     "ls r5 r11 0xc000002a",
     "ls_r5_r11_0xc000002a"},
    {{gt, r11, r6, 0xf000000f},
     "",
     "gt r11 r6 0xf000000f",
     "gt_r11_r6_0xf000000f"},
    {{ne, r11, r5, 0x000000ff},
     "",
     "ne r11 r5 0x000000ff",
     "ne_r11_r5_0x000000ff"},
    {{eq, r9, r14, 0x0ab00000},
     "",
     "eq r9 r14 0x0ab00000",
     "eq_r9_r14_0x0ab00000"},
    {{cs, r0, r10, 0x0002ac00},
     "",
     "cs r0 r10 0x0002ac00",
     "cs_r0_r10_0x0002ac00"},
    {{ls, r15, r15, 0x00003fc0},
     "",
     "ls r15 r15 0x00003fc0",
     "ls_r15_r15_0x00003fc0"},
    {{eq, r2, r2, 0xc000003f}, "", "eq r2 r2 0xc000003f", "eq_r2_r2_"
                                                          "0xc000003f"},
    {{ls, r10, r3, 0xfc000003},
     "",
     "ls r10 r3 0xfc000003",
     "ls_r10_r3_0xfc000003"},
    {{gt, r9, r2, 0x000ab000}, "", "gt r9 r2 0x000ab000", "gt_r9_r2_"
                                                          "0x000ab000"},
    {{vc, r7, r6, 0xb000000a}, "", "vc r7 r6 0xb000000a", "vc_r7_r6_"
                                                          "0xb000000a"},
    {{vs, r9, r0, 0x002ac000}, "", "vs r9 r0 0x002ac000", "vs_r9_r0_"
                                                          "0x002ac000"},
    {{hi, r10, r8, 0x2ac00000},
     "",
     "hi r10 r8 0x2ac00000",
     "hi_r10_r8_0x2ac00000"},
    {{vs, r15, r6, 0x003fc000},
     "",
     "vs r15 r6 0x003fc000",
     "vs_r15_r6_0x003fc000"},
    {{cc, r1, r8, 0x2ac00000}, "", "cc r1 r8 0x2ac00000", "cc_r1_r8_"
                                                          "0x2ac00000"},
    {{gt, r5, r14, 0x000ab000},
     "",
     "gt r5 r14 0x000ab000",
     "gt_r5_r14_0x000ab000"},
    {{ls, r2, r9, 0xc000003f}, "", "ls r2 r9 0xc000003f", "ls_r2_r9_"
                                                          "0xc000003f"},
    {{vs, r1, r10, 0x00000000},
     "",
     "vs r1 r10 0x00000000",
     "vs_r1_r10_0x00000000"},
    {{lt, r8, r12, 0x0ff00000},
     "",
     "lt r8 r12 0x0ff00000",
     "lt_r8_r12_0x0ff00000"},
    {{cc, r13, r14, 0x00002ac0},
     "",
     "cc r13 r14 0x00002ac0",
     "cc_r13_r14_0x00002ac0"},
    {{gt, r0, r3, 0x00003fc0}, "", "gt r0 r3 0x00003fc0", "gt_r0_r3_"
                                                          "0x00003fc0"},
    {{le, r0, r0, 0xc000003f}, "", "le r0 r0 0xc000003f", "le_r0_r0_"
                                                          "0xc000003f"},
    {{vc, r8, r8, 0xff000000}, "", "vc r8 r8 0xff000000", "vc_r8_r8_"
                                                          "0xff000000"},
    {{vc, r0, r5, 0x00002ac0}, "", "vc r0 r5 0x00002ac0", "vc_r0_r5_"
                                                          "0x00002ac0"},
    {{ls, r3, r10, 0x00ff0000},
     "",
     "ls r3 r10 0x00ff0000",
     "ls_r3_r10_0x00ff0000"},
    {{cc, r5, r2, 0x03fc0000}, "", "cc r5 r2 0x03fc0000", "cc_r5_r2_"
                                                          "0x03fc0000"},
    {{ls, r13, r8, 0xc000002a},
     "",
     "ls r13 r8 0xc000002a",
     "ls_r13_r8_0xc000002a"},
    {{vc, r14, r4, 0x3fc00000},
     "",
     "vc r14 r4 0x3fc00000",
     "vc_r14_r4_0x3fc00000"},
    {{eq, r7, r8, 0xac000002}, "", "eq r7 r8 0xac000002", "eq_r7_r8_"
                                                          "0xac000002"},
    {{al, r13, r13, 0x002ac000},
     "",
     "al r13 r13 0x002ac000",
     "al_r13_r13_0x002ac000"},
    {{vc, r0, r10, 0x000ff000},
     "",
     "vc r0 r10 0x000ff000",
     "vc_r0_r10_0x000ff000"},
    {{vc, r11, r12, 0x00002ac0},
     "",
     "vc r11 r12 0x00002ac0",
     "vc_r11_r12_0x00002ac0"},
    {{mi, r15, r4, 0x000ff000},
     "",
     "mi r15 r4 0x000ff000",
     "mi_r15_r4_0x000ff000"},
    {{eq, r3, r0, 0xfc000003}, "", "eq r3 r0 0xfc000003", "eq_r3_r0_"
                                                          "0xfc000003"},
    {{mi, r9, r8, 0xab000000}, "", "mi r9 r8 0xab000000", "mi_r9_r8_"
                                                          "0xab000000"},
    {{cc, r5, r7, 0xc000003f}, "", "cc r5 r7 0xc000003f", "cc_r5_r7_"
                                                          "0xc000003f"},
    {{eq, r9, r15, 0x002ac000},
     "",
     "eq r9 r15 0x002ac000",
     "eq_r9_r15_0x002ac000"},
    {{ne, r7, r5, 0x00000ab0}, "", "ne r7 r5 0x00000ab0", "ne_r7_r5_"
                                                          "0x00000ab0"},
    {{eq, r15, r12, 0x000002ac},
     "",
     "eq r15 r12 0x000002ac",
     "eq_r15_r12_0x000002ac"},
    {{cs, r0, r13, 0x00003fc0},
     "",
     "cs r0 r13 0x00003fc0",
     "cs_r0_r13_0x00003fc0"},
    {{gt, r13, r11, 0xac000002},
     "",
     "gt r13 r11 0xac000002",
     "gt_r13_r11_0xac000002"},
    {{pl, r4, r10, 0x2ac00000},
     "",
     "pl r4 r10 0x2ac00000",
     "pl_r4_r10_0x2ac00000"},
    {{ne, r3, r13, 0xac000002},
     "",
     "ne r3 r13 0xac000002",
     "ne_r3_r13_0xac000002"},
    {{eq, r8, r7, 0x000002ac}, "", "eq r8 r7 0x000002ac", "eq_r8_r7_"
                                                          "0x000002ac"},
    {{vs, r7, r6, 0xab000000}, "", "vs r7 r6 0xab000000", "vs_r7_r6_"
                                                          "0xab000000"},
    {{le, r14, r3, 0x00003fc0},
     "",
     "le r14 r3 0x00003fc0",
     "le_r14_r3_0x00003fc0"},
    {{mi, r3, r5, 0x0ab00000}, "", "mi r3 r5 0x0ab00000", "mi_r3_r5_"
                                                          "0x0ab00000"},
    {{lt, r9, r1, 0x000000ff}, "", "lt r9 r1 0x000000ff", "lt_r9_r1_"
                                                          "0x000000ff"},
    {{vc, r6, r2, 0xff000000}, "", "vc r6 r2 0xff000000", "vc_r6_r2_"
                                                          "0xff000000"},
    {{mi, r8, r3, 0xfc000003}, "", "mi r8 r3 0xfc000003", "mi_r8_r3_"
                                                          "0xfc000003"},
    {{gt, r14, r11, 0x000000ab},
     "",
     "gt r14 r11 0x000000ab",
     "gt_r14_r11_0x000000ab"},
    {{eq, r8, r14, 0x0000ff00},
     "",
     "eq r8 r14 0x0000ff00",
     "eq_r8_r14_0x0000ff00"},
    {{vs, r0, r5, 0x000002ac}, "", "vs r0 r5 0x000002ac", "vs_r0_r5_"
                                                          "0x000002ac"},
    {{cs, r15, r15, 0x00000ff0},
     "",
     "cs r15 r15 0x00000ff0",
     "cs_r15_r15_0x00000ff0"},
    {{le, r3, r0, 0x000000ff}, "", "le r3 r0 0x000000ff", "le_r3_r0_"
                                                          "0x000000ff"},
    {{vc, r3, r12, 0x000002ac},
     "",
     "vc r3 r12 0x000002ac",
     "vc_r3_r12_0x000002ac"},
    {{ne, r15, r9, 0x03fc0000},
     "",
     "ne r15 r9 0x03fc0000",
     "ne_r15_r9_0x03fc0000"},
    {{ls, r8, r14, 0x000002ac},
     "",
     "ls r8 r14 0x000002ac",
     "ls_r8_r14_0x000002ac"},
    {{eq, r7, r10, 0x03fc0000},
     "",
     "eq r7 r10 0x03fc0000",
     "eq_r7_r10_0x03fc0000"},
    {{vc, r0, r7, 0xab000000}, "", "vc r0 r7 0xab000000", "vc_r0_r7_"
                                                          "0xab000000"},
    {{vc, r3, r11, 0xff000000},
     "",
     "vc r3 r11 0xff000000",
     "vc_r3_r11_0xff000000"},
    {{cs, r14, r2, 0xfc000003},
     "",
     "cs r14 r2 0xfc000003",
     "cs_r14_r2_0xfc000003"},
    {{pl, r3, r11, 0x00ff0000},
     "",
     "pl r3 r11 0x00ff0000",
     "pl_r3_r11_0x00ff0000"},
    {{lt, r6, r1, 0x0002ac00}, "", "lt r6 r1 0x0002ac00", "lt_r6_r1_"
                                                          "0x0002ac00"},
    {{al, r15, r1, 0xf000000f},
     "",
     "al r15 r1 0xf000000f",
     "al_r15_r1_0xf000000f"},
    {{mi, r12, r7, 0x002ac000},
     "",
     "mi r12 r7 0x002ac000",
     "mi_r12_r7_0x002ac000"},
    {{vs, r9, r3, 0x000003fc}, "", "vs r9 r3 0x000003fc", "vs_r9_r3_"
                                                          "0x000003fc"},
    {{cc, r9, r14, 0x000000ff},
     "",
     "cc r9 r14 0x000000ff",
     "cc_r9_r14_0x000000ff"},
    {{ls, r9, r12, 0xac000002},
     "",
     "ls r9 r12 0xac000002",
     "ls_r9_r12_0xac000002"},
    {{al, r13, r13, 0xfc000003},
     "",
     "al r13 r13 0xfc000003",
     "al_r13_r13_0xfc000003"},
    {{lt, r14, r1, 0x02ac0000},
     "",
     "lt r14 r1 0x02ac0000",
     "lt_r14_r1_0x02ac0000"},
    {{le, r8, r15, 0x2ac00000},
     "",
     "le r8 r15 0x2ac00000",
     "le_r8_r15_0x2ac00000"},
    {{al, r10, r8, 0x0ab00000},
     "",
     "al r10 r8 0x0ab00000",
     "al_r10_r8_0x0ab00000"},
    {{eq, r3, r6, 0x0000ab00}, "", "eq r3 r6 0x0000ab00", "eq_r3_r6_"
                                                          "0x0000ab00"},
    {{cs, r6, r9, 0xab000000}, "", "cs r6 r9 0xab000000", "cs_r6_r9_"
                                                          "0xab000000"},
    {{al, r13, r1, 0xfc000003},
     "",
     "al r13 r1 0xfc000003",
     "al_r13_r1_0xfc000003"},
    {{ls, r4, r15, 0x000002ac},
     "",
     "ls r4 r15 0x000002ac",
     "ls_r4_r15_0x000002ac"},
    {{cs, r4, r10, 0x003fc000},
     "",
     "cs r4 r10 0x003fc000",
     "cs_r4_r10_0x003fc000"},
    {{eq, r2, r8, 0x000ab000}, "", "eq r2 r8 0x000ab000", "eq_r2_r8_"
                                                          "0x000ab000"},
    {{eq, r12, r2, 0x0003fc00},
     "",
     "eq r12 r2 0x0003fc00",
     "eq_r12_r2_0x0003fc00"},
    {{vs, r12, r10, 0x003fc000},
     "",
     "vs r12 r10 0x003fc000",
     "vs_r12_r10_0x003fc000"},
    {{eq, r9, r2, 0xab000000}, "", "eq r9 r2 0xab000000", "eq_r9_r2_"
                                                          "0xab000000"},
    {{cc, r6, r7, 0x0003fc00}, "", "cc r6 r7 0x0003fc00", "cc_r6_r7_"
                                                          "0x0003fc00"},
    {{mi, r8, r15, 0x0000ff00},
     "",
     "mi r8 r15 0x0000ff00",
     "mi_r8_r15_0x0000ff00"},
    {{ls, r2, r1, 0x0ff00000}, "", "ls r2 r1 0x0ff00000", "ls_r2_r1_"
                                                          "0x0ff00000"},
    {{cs, r12, r12, 0x00002ac0},
     "",
     "cs r12 r12 0x00002ac0",
     "cs_r12_r12_0x00002ac0"},
    {{hi, r1, r12, 0x000003fc},
     "",
     "hi r1 r12 0x000003fc",
     "hi_r1_r12_0x000003fc"},
    {{ls, r9, r0, 0x000003fc}, "", "ls r9 r0 0x000003fc", "ls_r9_r0_"
                                                          "0x000003fc"},
    {{ne, r6, r9, 0x00ff0000}, "", "ne r6 r9 0x00ff0000", "ne_r6_r9_"
                                                          "0x00ff0000"},
    {{al, r10, r5, 0x000000ff},
     "",
     "al r10 r5 0x000000ff",
     "al_r10_r5_0x000000ff"},
    {{pl, r10, r4, 0xf000000f},
     "",
     "pl r10 r4 0xf000000f",
     "pl_r10_r4_0xf000000f"},
    {{hi, r0, r11, 0x03fc0000},
     "",
     "hi r0 r11 0x03fc0000",
     "hi_r0_r11_0x03fc0000"},
    {{al, r6, r3, 0x00002ac0}, "", "al r6 r3 0x00002ac0", "al_r6_r3_"
                                                          "0x00002ac0"},
    {{ne, r12, r13, 0x0000ab00},
     "",
     "ne r12 r13 0x0000ab00",
     "ne_r12_r13_0x0000ab00"},
    {{mi, r13, r8, 0x00002ac0},
     "",
     "mi r13 r8 0x00002ac0",
     "mi_r13_r8_0x00002ac0"},
    {{ge, r13, r2, 0x003fc000},
     "",
     "ge r13 r2 0x003fc000",
     "ge_r13_r2_0x003fc000"},
    {{pl, r10, r15, 0x00ff0000},
     "",
     "pl r10 r15 0x00ff0000",
     "pl_r10_r15_0x00ff0000"},
    {{vs, r12, r7, 0xff000000},
     "",
     "vs r12 r7 0xff000000",
     "vs_r12_r7_0xff000000"},
    {{cs, r1, r3, 0xfc000003}, "", "cs r1 r3 0xfc000003", "cs_r1_r3_"
                                                          "0xfc000003"},
    {{ne, r9, r4, 0x000002ac}, "", "ne r9 r4 0x000002ac", "ne_r9_r4_"
                                                          "0x000002ac"},
    {{vs, r14, r3, 0x02ac0000},
     "",
     "vs r14 r3 0x02ac0000",
     "vs_r14_r3_0x02ac0000"},
    {{vs, r0, r2, 0x0ff00000}, "", "vs r0 r2 0x0ff00000", "vs_r0_r2_"
                                                          "0x0ff00000"},
    {{ne, r15, r5, 0x000000ab},
     "",
     "ne r15 r5 0x000000ab",
     "ne_r15_r5_0x000000ab"},
    {{vs, r9, r13, 0x000000ab},
     "",
     "vs r9 r13 0x000000ab",
     "vs_r9_r13_0x000000ab"},
    {{al, r3, r9, 0x0000ff00}, "", "al r3 r9 0x0000ff00", "al_r3_r9_"
                                                          "0x0000ff00"},
    {{cc, r5, r8, 0xac000002}, "", "cc r5 r8 0xac000002", "cc_r5_r8_"
                                                          "0xac000002"},
    {{ne, r0, r13, 0x00ab0000},
     "",
     "ne r0 r13 0x00ab0000",
     "ne_r0_r13_0x00ab0000"},
    {{vs, r3, r12, 0x000ff000},
     "",
     "vs r3 r12 0x000ff000",
     "vs_r3_r12_0x000ff000"},
    {{gt, r3, r12, 0x000003fc},
     "",
     "gt r3 r12 0x000003fc",
     "gt_r3_r12_0x000003fc"},
    {{ls, r1, r1, 0x002ac000}, "", "ls r1 r1 0x002ac000", "ls_r1_r1_"
                                                          "0x002ac000"},
    {{lt, r9, r10, 0x2ac00000},
     "",
     "lt r9 r10 0x2ac00000",
     "lt_r9_r10_0x2ac00000"},
    {{hi, r1, r9, 0x00003fc0}, "", "hi r1 r9 0x00003fc0", "hi_r1_r9_"
                                                          "0x00003fc0"},
    {{ge, r2, r13, 0x00002ac0},
     "",
     "ge r2 r13 0x00002ac0",
     "ge_r2_r13_0x00002ac0"},
    {{ls, r2, r7, 0xc000003f}, "", "ls r2 r7 0xc000003f", "ls_r2_r7_"
                                                          "0xc000003f"},
    {{eq, r0, r11, 0x3fc00000},
     "",
     "eq r0 r11 0x3fc00000",
     "eq_r0_r11_0x3fc00000"},
    {{vc, r13, r7, 0x0000ab00},
     "",
     "vc r13 r7 0x0000ab00",
     "vc_r13_r7_0x0000ab00"},
    {{le, r3, r6, 0x00002ac0}, "", "le r3 r6 0x00002ac0", "le_r3_r6_"
                                                          "0x00002ac0"},
    {{cc, r3, r11, 0x0ab00000},
     "",
     "cc r3 r11 0x0ab00000",
     "cc_r3_r11_0x0ab00000"},
    {{ls, r9, r11, 0x000002ac},
     "",
     "ls r9 r11 0x000002ac",
     "ls_r9_r11_0x000002ac"},
    {{ne, r11, r4, 0x00000ff0},
     "",
     "ne r11 r4 0x00000ff0",
     "ne_r11_r4_0x00000ff0"},
    {{cc, r3, r15, 0xfc000003},
     "",
     "cc r3 r15 0xfc000003",
     "cc_r3_r15_0xfc000003"},
    {{ne, r8, r3, 0x00003fc0}, "", "ne r8 r3 0x00003fc0", "ne_r8_r3_"
                                                          "0x00003fc0"},
    {{vs, r3, r10, 0xff000000},
     "",
     "vs r3 r10 0xff000000",
     "vs_r3_r10_0xff000000"},
    {{mi, r9, r0, 0x000002ac}, "", "mi r9 r0 0x000002ac", "mi_r9_r0_"
                                                          "0x000002ac"},
    {{cc, r6, r3, 0x0003fc00}, "", "cc r6 r3 0x0003fc00", "cc_r6_r3_"
                                                          "0x0003fc00"},
    {{ge, r11, r11, 0xac000002},
     "",
     "ge r11 r11 0xac000002",
     "ge_r11_r11_0xac000002"},
    {{eq, r3, r13, 0x003fc000},
     "",
     "eq r3 r13 0x003fc000",
     "eq_r3_r13_0x003fc000"},
    {{le, r15, r4, 0x2ac00000},
     "",
     "le r15 r4 0x2ac00000",
     "le_r15_r4_0x2ac00000"},
    {{le, r15, r4, 0x03fc0000},
     "",
     "le r15 r4 0x03fc0000",
     "le_r15_r4_0x03fc0000"},
    {{hi, r4, r15, 0xc000002a},
     "",
     "hi r4 r15 0xc000002a",
     "hi_r4_r15_0xc000002a"},
    {{ge, r8, r15, 0xac000002},
     "",
     "ge r8 r15 0xac000002",
     "ge_r8_r15_0xac000002"},
    {{pl, r10, r7, 0x002ac000},
     "",
     "pl r10 r7 0x002ac000",
     "pl_r10_r7_0x002ac000"},
    {{vs, r14, r1, 0x000000ff},
     "",
     "vs r14 r1 0x000000ff",
     "vs_r14_r1_0x000000ff"},
    {{hi, r4, r4, 0x00000ab0}, "", "hi r4 r4 0x00000ab0", "hi_r4_r4_"
                                                          "0x00000ab0"},
    {{gt, r0, r2, 0xac000002}, "", "gt r0 r2 0xac000002", "gt_r0_r2_"
                                                          "0xac000002"},
    {{ls, r10, r1, 0x000ab000},
     "",
     "ls r10 r1 0x000ab000",
     "ls_r10_r1_0x000ab000"},
    {{ge, r9, r4, 0xc000003f}, "", "ge r9 r4 0xc000003f", "ge_r9_r4_"
                                                          "0xc000003f"},
    {{eq, r12, r13, 0x000ab000},
     "",
     "eq r12 r13 0x000ab000",
     "eq_r12_r13_0x000ab000"},
    {{eq, r8, r5, 0x0003fc00}, "", "eq r8 r5 0x0003fc00", "eq_r8_r5_"
                                                          "0x0003fc00"},
    {{lt, r1, r1, 0x0002ac00}, "", "lt r1 r1 0x0002ac00", "lt_r1_r1_"
                                                          "0x0002ac00"},
    {{lt, r14, r14, 0x00000ff0},
     "",
     "lt r14 r14 0x00000ff0",
     "lt_r14_r14_0x00000ff0"},
    {{gt, r0, r7, 0x000ff000}, "", "gt r0 r7 0x000ff000", "gt_r0_r7_"
                                                          "0x000ff000"},
    {{eq, r7, r13, 0x0002ac00},
     "",
     "eq r7 r13 0x0002ac00",
     "eq_r7_r13_0x0002ac00"},
    {{le, r4, r9, 0x0000ff00}, "", "le r4 r9 0x0000ff00", "le_r4_r9_"
                                                          "0x0000ff00"},
    {{le, r4, r12, 0xab000000},
     "",
     "le r4 r12 0xab000000",
     "le_r4_r12_0xab000000"},
    {{mi, r1, r8, 0x02ac0000}, "", "mi r1 r8 0x02ac0000", "mi_r1_r8_"
                                                          "0x02ac0000"},
    {{al, r9, r11, 0xc000003f},
     "",
     "al r9 r11 0xc000003f",
     "al_r9_r11_0xc000003f"},
    {{cs, r13, r4, 0x0ff00000},
     "",
     "cs r13 r4 0x0ff00000",
     "cs_r13_r4_0x0ff00000"},
    {{lt, r14, r11, 0x0000ff00},
     "",
     "lt r14 r11 0x0000ff00",
     "lt_r14_r11_0x0000ff00"},
    {{cc, r2, r13, 0x3fc00000},
     "",
     "cc r2 r13 0x3fc00000",
     "cc_r2_r13_0x3fc00000"},
    {{lt, r4, r2, 0xc000002a}, "", "lt r4 r2 0xc000002a", "lt_r4_r2_"
                                                          "0xc000002a"},
    {{vs, r9, r14, 0x00002ac0},
     "",
     "vs r9 r14 0x00002ac0",
     "vs_r9_r14_0x00002ac0"},
    {{eq, r1, r5, 0xc000002a}, "", "eq r1 r5 0xc000002a", "eq_r1_r5_"
                                                          "0xc000002a"},
    {{vc, r12, r5, 0x000003fc},
     "",
     "vc r12 r5 0x000003fc",
     "vc_r12_r5_0x000003fc"},
    {{mi, r12, r4, 0xfc000003},
     "",
     "mi r12 r4 0xfc000003",
     "mi_r12_r4_0xfc000003"},
    {{cc, r4, r15, 0x02ac0000},
     "",
     "cc r4 r15 0x02ac0000",
     "cc_r4_r15_0x02ac0000"},
    {{ls, r5, r10, 0x0000ab00},
     "",
     "ls r5 r10 0x0000ab00",
     "ls_r5_r10_0x0000ab00"},
    {{cc, r9, r9, 0x000003fc}, "", "cc r9 r9 0x000003fc", "cc_r9_r9_"
                                                          "0x000003fc"},
    {{pl, r5, r13, 0xff000000},
     "",
     "pl r5 r13 0xff000000",
     "pl_r5_r13_0xff000000"},
    {{al, r0, r1, 0xac000002}, "", "al r0 r1 0xac000002", "al_r0_r1_"
                                                          "0xac000002"},
    {{al, r12, r13, 0x00ff0000},
     "",
     "al r12 r13 0x00ff0000",
     "al_r12_r13_0x00ff0000"},
    {{hi, r6, r2, 0x000ff000}, "", "hi r6 r2 0x000ff000", "hi_r6_r2_"
                                                          "0x000ff000"},
    {{gt, r13, r9, 0x000000ab},
     "",
     "gt r13 r9 0x000000ab",
     "gt_r13_r9_0x000000ab"},
    {{hi, r14, r7, 0x0002ac00},
     "",
     "hi r14 r7 0x0002ac00",
     "hi_r14_r7_0x0002ac00"},
    {{lt, r4, r10, 0xb000000a},
     "",
     "lt r4 r10 0xb000000a",
     "lt_r4_r10_0xb000000a"},
    {{cs, r1, r14, 0x00000ff0},
     "",
     "cs r1 r14 0x00000ff0",
     "cs_r1_r14_0x00000ff0"},
    {{hi, r15, r8, 0x0002ac00},
     "",
     "hi r15 r8 0x0002ac00",
     "hi_r15_r8_0x0002ac00"},
    {{cs, r4, r10, 0x000000ab},
     "",
     "cs r4 r10 0x000000ab",
     "cs_r4_r10_0x000000ab"},
    {{gt, r0, r9, 0x2ac00000}, "", "gt r0 r9 0x2ac00000", "gt_r0_r9_"
                                                          "0x2ac00000"},
    {{cc, r2, r6, 0x0000ab00}, "", "cc r2 r6 0x0000ab00", "cc_r2_r6_"
                                                          "0x0000ab00"},
    {{mi, r3, r9, 0x0000ff00}, "", "mi r3 r9 0x0000ff00", "mi_r3_r9_"
                                                          "0x0000ff00"},
    {{lt, r6, r13, 0xc000002a},
     "",
     "lt r6 r13 0xc000002a",
     "lt_r6_r13_0xc000002a"},
    {{pl, r7, r7, 0x003fc000}, "", "pl r7 r7 0x003fc000", "pl_r7_r7_"
                                                          "0x003fc000"},
    {{cc, r1, r6, 0x003fc000}, "", "cc r1 r6 0x003fc000", "cc_r1_r6_"
                                                          "0x003fc000"},
    {{le, r9, r11, 0x000ff000},
     "",
     "le r9 r11 0x000ff000",
     "le_r9_r11_0x000ff000"},
    {{pl, r4, r7, 0xb000000a}, "", "pl r4 r7 0xb000000a", "pl_r4_r7_"
                                                          "0xb000000a"},
    {{al, r15, r5, 0x0000ff00},
     "",
     "al r15 r5 0x0000ff00",
     "al_r15_r5_0x0000ff00"},
    {{al, r11, r10, 0x00ff0000},
     "",
     "al r11 r10 0x00ff0000",
     "al_r11_r10_0x00ff0000"},
    {{pl, r9, r5, 0x00003fc0}, "", "pl r9 r5 0x00003fc0", "pl_r9_r5_"
                                                          "0x00003fc0"},
    {{ls, r6, r11, 0xc000003f},
     "",
     "ls r6 r11 0xc000003f",
     "ls_r6_r11_0xc000003f"},
    {{ge, r9, r15, 0x0ab00000},
     "",
     "ge r9 r15 0x0ab00000",
     "ge_r9_r15_0x0ab00000"},
    {{le, r9, r10, 0x2ac00000},
     "",
     "le r9 r10 0x2ac00000",
     "le_r9_r10_0x2ac00000"},
    {{ne, r0, r3, 0x00002ac0}, "", "ne r0 r3 0x00002ac0", "ne_r0_r3_"
                                                          "0x00002ac0"},
    {{gt, r13, r15, 0x00003fc0},
     "",
     "gt r13 r15 0x00003fc0",
     "gt_r13_r15_0x00003fc0"},
    {{ls, r4, r4, 0x00000000}, "", "ls r4 r4 0x00000000", "ls_r4_r4_"
                                                          "0x00000000"},
    {{hi, r6, r8, 0xff000000}, "", "hi r6 r8 0xff000000", "hi_r6_r8_"
                                                          "0xff000000"},
    {{cc, r11, r5, 0x0003fc00},
     "",
     "cc r11 r5 0x0003fc00",
     "cc_r11_r5_0x0003fc00"},
    {{vs, r5, r0, 0x00002ac0}, "", "vs r5 r0 0x00002ac0", "vs_r5_r0_"
                                                          "0x00002ac0"},
    {{vs, r1, r12, 0x0000ff00},
     "",
     "vs r1 r12 0x0000ff00",
     "vs_r1_r12_0x0000ff00"}};

// These headers each contain an array of `TestResult` with the reference output
// values. The reference arrays are names `kReference{mnemonic}`.
#include "aarch32/traces/assembler-cond-rd-rn-operand-const-a32-adc.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-const-a32-adcs.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-const-a32-add.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-const-a32-adds.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-const-a32-and.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-const-a32-ands.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-const-a32-bic.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-const-a32-bics.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-const-a32-eor.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-const-a32-eors.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-const-a32-orr.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-const-a32-orrs.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-const-a32-rsb.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-const-a32-rsbs.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-const-a32-rsc.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-const-a32-rscs.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-const-a32-sbc.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-const-a32-sbcs.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-const-a32-sub.h"
#include "aarch32/traces/assembler-cond-rd-rn-operand-const-a32-subs.h"


// The maximum number of errors to report in detail for each test.
static const unsigned kErrorReportLimit = 8;

typedef void (MacroAssembler::*Fn)(Condition cond,
                                   Register rd,
                                   Register rn,
                                   const Operand& op);

static void TestHelper(Fn instruction,
                       const char* mnemonic,
                       const TestResult reference[]) {
  unsigned total_error_count = 0;
  MacroAssembler masm(BUF_SIZE);

  masm.UseA32();

  for (unsigned i = 0; i < ARRAY_SIZE(kTests); i++) {
    // Values to pass to the macro-assembler.
    Condition cond = kTests[i].operands.cond;
    Register rd = kTests[i].operands.rd;
    Register rn = kTests[i].operands.rn;
    uint32_t immediate = kTests[i].operands.immediate;
    Operand op(immediate);

    uint32_t start = masm.GetCursorOffset();
    (masm.*instruction)(cond, rd, rn, op);
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
      "AARCH32_ASSEMBLER_COND_RD_RN_OPERAND_CONST_A32_" #mnemonic,          \
      &Test_##mnemonic);
FOREACH_INSTRUCTION(TEST)
#undef TEST

}  // aarch32
}  // vixl
