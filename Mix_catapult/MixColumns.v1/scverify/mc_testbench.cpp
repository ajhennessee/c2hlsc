// ----------------------------------------------------------------------------
// SystemC Testbench Body
//
//    HLS version: 2023.1_2/1049935 Production Release
//       HLS date: Sat Jun 10 10:53:51 PDT 2023
//  Flow Packages: HDL_Tcl 8.0a, SCVerify 10.4
//
//   Generated by: lc4976@hansolo.poly.edu
// Generated date: Tue Apr 09 23:24:52 EDT 2024
//
// ----------------------------------------------------------------------------
// 
// -------------------------------------
// mc_testbench
// SCVerify mc_testbench SC_MODULE
// -------------------------------------
// 
#include "mc_testbench.h"
#include <mc_testbench_util.h>
#include <mc_simulator_extensions.h>

mc_testbench* mc_testbench::that;
bool testbench::enable_idle_sync_mode;
unsigned short testbench::idle_sync_stable_cycles;
void testbench::set_enable_stalls(bool flag) { mc_testbench::set_enable_stalls(flag); }
void testbench::reset_request() { mc_testbench::that->reset_request(); }
void mc_testbench_reset_request() { mc_testbench::that->reset_request(); }
bool testbench::_dut_inst = false;
bool testbench::dut_inst() { return _dut_inst; }
bool mc_testbench_dut_inst() { return testbench::dut_inst(); }
bool testbench::set_dut_inst( bool _inst ) { if(_dut_inst==false) _dut_inst=_inst; return _dut_inst; }
bool mc_testbench_set_dut_inst( bool _inst ) { return testbench::set_dut_inst(_inst); }
void mc_testbench_wait_for_idle_sync() { mc_testbench::wait_for_idle_sync(); }
bool testbench::state_ignore;
void mc_testbench_state_skip(bool v) { testbench::state_skip = v; }
bool testbench::state_skip;
bool testbench::state_skip_quiet;
bool testbench::state_skip_once;
bool testbench::state_skip_noerr;
int  testbench::state_array_comp_first;
int  testbench::state_array_comp_last;
mc_wait_ctrl testbench::state_IN_wait_ctrl;
bool testbench::state_use_mask;
unsigned char testbench::state_output_mask;
mc_wait_ctrl testbench::state_wait_ctrl;
#ifndef CCS_SCVERIFY_USE_CCS_BLOCK
extern "C++" void MixColumns(unsigned char state[4][4]);
#endif
#ifndef CCS_SCVERIFY_USE_CCS_BLOCK
void testbench::exec_MixColumns(unsigned char state[4][4]) {
   return mc_testbench::exec_MixColumns(state);
}
#endif

// ============================================
// Function: wait_for_idle_sync
// --------------------------------------------

void mc_testbench::wait_for_idle_sync()
{
   if (testbench::enable_idle_sync_mode) {
     std::cout << "mc_testbench: Idle synchronization disabled, requires design with stall controls." << std::endl;
     testbench::enable_idle_sync_mode = false;
     that->cpp_testbench_active.write(true);
   }
}
// ============================================
// Function: set_enable_stalls
// --------------------------------------------

void mc_testbench::set_enable_stalls(bool flag)
{
   if (flag) {
     std::cout << "Enabling STALL_FLAG toggling" << std::endl;
     that->enable_stalls.write(sc_dt::Log_1);
   } else {
     std::cout << "Disabling STALL_FLAG toggling" << std::endl;
     that->enable_stalls.write(sc_dt::Log_0);
   }
}
// ============================================
// Function: reset_request
// --------------------------------------------

void mc_testbench::reset_request()
{
   reset_request_event.notify(0,SC_NS);
}
// ============================================
// Function: capture_state_IN
// --------------------------------------------

void mc_testbench::capture_state_IN( unsigned char state[4][4])
{
   if (state_IN_capture_count == wait_cnt)
      wait_on_input_required();
   if (_capture_state_IN && !testbench::state_ignore)
   {
      int cur_iter = state_IN_iteration_count;
      ++state_IN_iteration_count;
      mgc_sysc_ver_array1D<unsigned char,16> state_IN_tmp;
      int state_linear_idx = 0;
      for (int state_idx_0 = 0; state_idx_0 < 4; ++state_idx_0)
         for (int state_idx_1 = 0; state_idx_1 < 4; ++state_idx_1)
            state_IN_tmp[state_linear_idx++] = state[state_idx_0][state_idx_1];
      ccs_state_IN->put(state_IN_tmp);
      ++state_IN_capture_count;
      mc_testbench_util::process_wait_ctrl("state_IN",testbench::state_IN_wait_ctrl,ccs_wait_ctrl_state_IN.operator->(),cur_iter,state_IN_capture_count,0);
   }
   testbench::state_ignore = false;
}
// ============================================
// Function: capture_state
// --------------------------------------------

void mc_testbench::capture_state( unsigned char state[4][4])
{
   if (_capture_state)
   {
      int cur_iter = state_iteration_count;
      ++state_iteration_count;
      mc_golden_info< mgc_sysc_ver_array1D<unsigned char,16>, MaskPacket<0, 8> > state_tmp(testbench::state_ignore, false, state_iteration_count);
      state_tmp._data.mc_testbench_process_array_bounds("state",testbench::state_array_comp_first,testbench::state_array_comp_last,15,0);
      // BEGIN: testbench output_mask control for field_name state
      if ( testbench::state_use_mask ) {
         sc_lv<8> tmp_mask_lv;
         type_to_vector(testbench::state_output_mask, 8, tmp_mask_lv);
         state_tmp._use_mask = true;
         state_tmp._packet._mask = tmp_mask_lv;
      }
      // END: testbench output_mask control for field_name state
      int state_linear_idx = 0;
      for (int state_idx_0 = 0; state_idx_0 < 4; ++state_idx_0)
         for (int state_idx_1 = 0; state_idx_1 < 4; ++state_idx_1)
            state_tmp._data[state_linear_idx++] = state[state_idx_0][state_idx_1];
      if (!testbench::state_skip) {
         state_golden.put(state_tmp);
         ++state_capture_count;
      } else {
         if (!testbench::state_skip_quiet || !testbench::state_skip_once) {
            std::ostringstream msg; msg.str("");
            msg << "testbench::state_skip=true for iteration=" << state_iteration_count << " @ " << sc_time_stamp();
            SC_REPORT_WARNING("User testbench", msg.str().c_str());
            testbench::state_skip_once = true;
         }
      }
      mc_testbench_util::process_wait_ctrl("state",testbench::state_wait_ctrl,ccs_wait_ctrl_state.operator->(),cur_iter,state_capture_count,0);
      testbench::state_use_mask = false;
   }
   testbench::state_ignore = false;
   testbench::state_skip = false;
}
// ============================================
// Function: wait_on_input_required
// --------------------------------------------

void mc_testbench::wait_on_input_required()
{
   ++wait_cnt;
   wait(SC_ZERO_TIME); // get fifos a chance to update
   ++period_counter;
   sc_time timeout = sc_time_stamp() - previous_timestamp;
   if (calculate_period && sc_time_stamp() > SC_ZERO_TIME && sc_time_stamp() != previous_timestamp && sc_time_stamp() != timeout) {
      average_period = (average_period + timeout) / 2;
   }
   previous_timestamp = sc_time_stamp();
   while (atleast_one_active_input) {
      if (_capture_state_IN && ccs_state_IN->used() == 0) return;
      that->cpp_testbench_active.write(false);
      if (average_period > SC_ZERO_TIME && sc_time_stamp() != timeout)
         wait(average_period * 10, ccs_state_IN->ok_to_put());
      else
         wait(ccs_state_IN->ok_to_put());
      that->cpp_testbench_active.write(true);
      if (timed_out()) {
         calculate_period = false;
         return;
      }
   }
}
// ============================================
// Function: capture_IN
// --------------------------------------------

void mc_testbench::capture_IN(unsigned char state[4][4])
{
   that->capture_state_IN(state);
}
// ============================================
// Function: capture_OUT
// --------------------------------------------

void mc_testbench::capture_OUT(unsigned char state[4][4])
{
   that->capture_state(state);
}
// ============================================
// Function: exec_MixColumns
// --------------------------------------------

void mc_testbench::exec_MixColumns(unsigned char state[4][4])
{
   #ifndef CCS_SCVERIFY_USE_CCS_BLOCK
   wait_for_idle_sync();
   capture_IN(state);
   MixColumns(state);
   // throttle ac_channel based on number of calls to chan::size() or chan::empty() or chan::nb_read() (but not chan::available()) 
   if (1) {
      int cnt=0;
      if (cnt) std::cout << "mc_testbench.cpp: CONTINUES @ " << sc_time_stamp() << std::endl;
      if (cnt) that->cpp_testbench_active.write(true);
   }
   capture_OUT(state);
   #else
   #endif
}
// ============================================
// Function: start_of_simulation
// --------------------------------------------

void mc_testbench::start_of_simulation()
{
   set_enable_stalls(false);
   if (ac_env::read_int("SCVerify_AUTOWAIT", 0) != 0) { //explicitly 0 means off
      SC_REPORT_INFO(name(), "SCVerify AUTOWAIT is enabled for this simulation.");
   }
}
// ============================================
// Function: end_of_simulation
// --------------------------------------------

void mc_testbench::end_of_simulation()
{
   if (!_checked_results) {
      SC_REPORT_INFO(name(), "Testbench exited early or ran into deadlock");
      check_results();
   }
}
// ============================================
// Function: check_results
// --------------------------------------------

void mc_testbench::check_results()
{
   if (_checked_results) return;
   _checked_results = true;
   cout<<endl;
   cout<<"Checking results"<<endl;
   if (main_exit_code) _failed = true;
   int _num_outputs_checked = 0;
   bool _has_capture_counts = false;
   std::ostringstream mctb_msg;
   
   if (!_capture_state) {
      cout<<"'state' - warning, output was optimized away"<<endl;
   } else {
      _num_outputs_checked++;
      _failed |= state_comp->check_results(state_capture_count,testbench::state_skip_noerr);
      _has_capture_counts |= !!(state_capture_count);
   }
   cout<<endl;
   if (_num_outputs_checked == 0) {
      cout<<"Error: All outputs were optimized away. No output values were compared."<<endl;
      _failed = _failed || (_num_outputs_checked == 0);
   }
   if (!_has_capture_counts) {
      cout<<"Error: Nothing to compare, all output capture counts are zero."<<endl;
      _failed = true;
   }
   if (main_exit_code) cout << "Error: C++ Testbench 'main()' returned a non-zero exit code ("<<main_exit_code<<"). Check your testbench." <<endl;
   mctb_msg.clear();
   if (_failed) mctb_msg << "Simulation FAILED";
   else         mctb_msg << "Simulation PASSED";
   mctb_msg << " @ " << sc_time_stamp();
   if (_channel_mismatch && _failed)
      mctb_msg << endl << "An input channel was switched before the input fifo was fully empty. Check your testbench.";
   SC_REPORT_INFO(this->name(), mctb_msg.str().c_str());
}
// ============================================
// Function: failed
// --------------------------------------------

bool mc_testbench::failed()
{
   return _failed;
}
// ============================================
// Function: set_failed
// --------------------------------------------

void mc_testbench::set_failed(bool fail)
{
   _failed = fail;
}
// ---------------------------------------------------------------
// Process: SC_METHOD wait_for_end
// Static sensitivity: sensitive << clk.pos() << testbench_end_event;

void mc_testbench::wait_for_end() {
   // If run() has not finished, we do nothing here
   if (!testbench_ended) return;
   // check for completed outputs
   if (state_comp->get_compare_count() < state_capture_count) {testbench_end_event.notify(1,SC_NS); return;}
   // If we made it here, all outputs have flushed. Check the results
   testbench_aw_event.notify(SC_ZERO_TIME);
   SC_REPORT_INFO(name(), "Simulation completed");
   check_results();
   sc_stop();
}
// ---------------------------------------------------------------
// Process: SC_THREAD run
// Static sensitivity: 

void mc_testbench::run() {
   testbench::enable_idle_sync_mode = false;
   testbench::idle_sync_stable_cycles = 1;
   _channel_mismatch = false;
   testbench::state_ignore = false;
   testbench::state_skip = false;
   testbench::state_skip_quiet = false;
   testbench::state_skip_once = false;
   testbench::state_skip_noerr = false;
   testbench::state_array_comp_first = -1;
   testbench::state_array_comp_last = -1;
   testbench::state_IN_wait_ctrl.clear();
   state_IN_capture_count = 0;
   state_IN_iteration_count = 0;
   testbench::state_use_mask = false;
   testbench::state_output_mask = (unsigned char) ~0;
   testbench::state_wait_ctrl.clear();
   state_capture_count = 0;
   state_iteration_count = 0;
   testbench testbench_inst(sc_argc(), sc_argv());
   main_exit_code = testbench_inst.main();
   cout<<"Info: Execution of user-supplied C++ testbench 'main()' has completed with exit code = " << main_exit_code << endl;
   cout<<endl;
   cout<<"Info: Collecting data completed"<<endl;
   cout<<"   captured "<<state_IN_capture_count<<" values of state_IN"<<endl;
   cout<<"   captured "<<state_capture_count<<" values of state"<<endl;
   testbench_ended = true;
   testbench_end_event.notify(SC_ZERO_TIME);
}
#ifdef CCS_SCVERIFY_USE_CCS_BLOCK
#include "ccs_block_macros.cpp"
#endif
