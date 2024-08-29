// ----------------------------------------------------------------------------
// User Testbench Interface Header
//
//    HLS version: 2023.1_2/1049935 Production Release
//       HLS date: Sat Jun 10 10:53:51 PDT 2023
//  Flow Packages: HDL_Tcl 8.0a, SCVerify 10.4
//
//   Generated by: lc4976@hansolo.poly.edu
// Generated date: Tue Apr 09 22:33:58 EDT 2024
//
// ----------------------------------------------------------------------------

#ifndef CCS_TESTBENCH_H
#define CCS_TESTBENCH_H

#include "mc_wait_ctrl.h"
#include <string.h>
#include <iostream>

class testbench
{
   public:
   int argc;
   char** argv;
   int main(); //CCS_MAIN
   static bool enable_idle_sync_mode;
   static unsigned short idle_sync_stable_cycles;
   static void set_enable_stalls(bool flag);
   static void reset_request();
   static bool _dut_inst;
   static bool dut_inst();
   static bool set_dut_inst( bool _inst );
   static bool round_ignore;
   static bool round_skip;
   static bool round_skip_quiet;
   static bool round_skip_once;
   static bool round_skip_noerr;
   static int  round_array_comp_first;
   static int  round_array_comp_last;
   static mc_wait_ctrl round_wait_ctrl;
   static bool state_ignore;
   static bool state_skip;
   static bool state_skip_quiet;
   static bool state_skip_once;
   static bool state_skip_noerr;
   static int  state_array_comp_first;
   static int  state_array_comp_last;
   static mc_wait_ctrl state_IN_wait_ctrl;
   static bool state_use_mask;
   static unsigned char state_output_mask;
   static mc_wait_ctrl state_wait_ctrl;
   static bool RoundKey_ignore;
   static bool RoundKey_skip;
   static bool RoundKey_skip_quiet;
   static bool RoundKey_skip_once;
   static bool RoundKey_skip_noerr;
   static int  RoundKey_array_comp_first;
   static int  RoundKey_array_comp_last;
   static mc_wait_ctrl RoundKey_wait_ctrl;
   #ifndef CCS_SCVERIFY_USE_CCS_BLOCK
   static void exec_AddRoundKey(unsigned char round, unsigned char state[4][4], const unsigned char *RoundKey);
   #endif
   explicit testbench(int _argc, const char* const *_argv)
      :argc(_argc), argv(const_cast<char**>(_argv))
   {
   }
   ~testbench()
   {
   }
   private:
   testbench() {}
};
extern void mc_testbench_reset_request();
extern bool mc_testbench_dut_inst();
extern bool mc_testbench_set_dut_inst( bool _inst );
extern void mc_testbench_wait_for_idle_sync();
extern void mc_testbench_round_skip(bool v);
extern void mc_testbench_state_skip(bool v);
extern void mc_testbench_RoundKey_skip(bool v);
#endif //CCS_TESTBENCH_H
