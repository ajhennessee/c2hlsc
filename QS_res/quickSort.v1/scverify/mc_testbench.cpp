// ----------------------------------------------------------------------------
// SystemC Testbench Body
//
//    HLS version: 2023.1_2/1049935 Production Release
//       HLS date: Sat Jun 10 10:53:51 PDT 2023
//  Flow Packages: HDL_Tcl 8.0a, SCVerify 10.4
//
//   Generated by: lc4976@hansolo.poly.edu
// Generated date: Tue Apr 09 22:15:37 EDT 2024
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
bool testbench::arr_ignore;
void mc_testbench_arr_skip(bool v) { testbench::arr_skip = v; }
bool testbench::arr_skip;
bool testbench::arr_skip_quiet;
bool testbench::arr_skip_once;
bool testbench::arr_skip_noerr;
int  testbench::arr_array_comp_first;
int  testbench::arr_array_comp_last;
mc_wait_ctrl testbench::arr_IN_wait_ctrl;
bool testbench::arr_use_mask;
int testbench::arr_output_mask;
mc_wait_ctrl testbench::arr_wait_ctrl;
bool testbench::low_ignore;
void mc_testbench_low_skip(bool v) { testbench::low_skip = v; }
bool testbench::low_skip;
bool testbench::low_skip_quiet;
bool testbench::low_skip_once;
bool testbench::low_skip_noerr;
int  testbench::low_array_comp_first;
int  testbench::low_array_comp_last;
mc_wait_ctrl testbench::low_wait_ctrl;
bool testbench::high_ignore;
void mc_testbench_high_skip(bool v) { testbench::high_skip = v; }
bool testbench::high_skip;
bool testbench::high_skip_quiet;
bool testbench::high_skip_once;
bool testbench::high_skip_noerr;
int  testbench::high_array_comp_first;
int  testbench::high_array_comp_last;
mc_wait_ctrl testbench::high_wait_ctrl;
#ifndef CCS_SCVERIFY_USE_CCS_BLOCK
extern "C++" void quickSort(int arr[64], int low, int high);
#endif
#ifndef CCS_SCVERIFY_USE_CCS_BLOCK
void testbench::exec_quickSort(int arr[64], int low, int high) {
   return mc_testbench::exec_quickSort(arr, low, high);
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
// Function: capture_arr_IN
// --------------------------------------------

void mc_testbench::capture_arr_IN( int arr[64])
{
   if (arr_IN_capture_count == wait_cnt)
      wait_on_input_required();
   if (_capture_arr_IN && !testbench::arr_ignore)
   {
      int cur_iter = arr_IN_iteration_count;
      ++arr_IN_iteration_count;
      mgc_sysc_ver_array1D<int,64> arr_IN_tmp;
      int arr_linear_idx = 0;
      for (int arr_idx_0 = 0; arr_idx_0 < 64; ++arr_idx_0)
         arr_IN_tmp[arr_linear_idx++] = arr[arr_idx_0];
      ccs_arr_IN->put(arr_IN_tmp);
      ++arr_IN_capture_count;
      mc_testbench_util::process_wait_ctrl("arr_IN",testbench::arr_IN_wait_ctrl,ccs_wait_ctrl_arr_IN.operator->(),cur_iter,arr_IN_capture_count,0);
   }
   testbench::arr_ignore = false;
}
// ============================================
// Function: capture_arr
// --------------------------------------------

void mc_testbench::capture_arr( int arr[64])
{
   if (_capture_arr)
   {
      int cur_iter = arr_iteration_count;
      ++arr_iteration_count;
      mc_golden_info< mgc_sysc_ver_array1D<int,64>, MaskPacket<0, 32> > arr_tmp(testbench::arr_ignore, false, arr_iteration_count);
      arr_tmp._data.mc_testbench_process_array_bounds("arr",testbench::arr_array_comp_first,testbench::arr_array_comp_last,63,0);
      // BEGIN: testbench output_mask control for field_name arr
      if ( testbench::arr_use_mask ) {
         sc_lv<32> tmp_mask_lv;
         type_to_vector(testbench::arr_output_mask, 32, tmp_mask_lv);
         arr_tmp._use_mask = true;
         arr_tmp._packet._mask = tmp_mask_lv;
      }
      // END: testbench output_mask control for field_name arr
      int arr_linear_idx = 0;
      for (int arr_idx_0 = 0; arr_idx_0 < 64; ++arr_idx_0)
         arr_tmp._data[arr_linear_idx++] = arr[arr_idx_0];
      if (!testbench::arr_skip) {
         arr_golden.put(arr_tmp);
         ++arr_capture_count;
      } else {
         if (!testbench::arr_skip_quiet || !testbench::arr_skip_once) {
            std::ostringstream msg; msg.str("");
            msg << "testbench::arr_skip=true for iteration=" << arr_iteration_count << " @ " << sc_time_stamp();
            SC_REPORT_WARNING("User testbench", msg.str().c_str());
            testbench::arr_skip_once = true;
         }
      }
      mc_testbench_util::process_wait_ctrl("arr",testbench::arr_wait_ctrl,ccs_wait_ctrl_arr.operator->(),cur_iter,arr_capture_count,0);
      testbench::arr_use_mask = false;
   }
   testbench::arr_ignore = false;
   testbench::arr_skip = false;
}
// ============================================
// Function: capture_low
// --------------------------------------------

void mc_testbench::capture_low(int low)
{
   if (low_capture_count == wait_cnt)
      wait_on_input_required();
   if (_capture_low && !testbench::low_ignore)
   {
      int cur_iter = low_iteration_count;
      ++low_iteration_count;
      ccs_low->put(low); // THIS
      ++low_capture_count;
      mc_testbench_util::process_wait_ctrl("low",testbench::low_wait_ctrl,ccs_wait_ctrl_low.operator->(),cur_iter,low_capture_count,0);
   }
   testbench::low_ignore = false;
}
// ============================================
// Function: capture_high
// --------------------------------------------

void mc_testbench::capture_high(int high)
{
   if (high_capture_count == wait_cnt)
      wait_on_input_required();
   if (_capture_high && !testbench::high_ignore)
   {
      int cur_iter = high_iteration_count;
      ++high_iteration_count;
      ccs_high->put(high); // THIS
      ++high_capture_count;
      mc_testbench_util::process_wait_ctrl("high",testbench::high_wait_ctrl,ccs_wait_ctrl_high.operator->(),cur_iter,high_capture_count,0);
   }
   testbench::high_ignore = false;
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
      if (_capture_arr_IN && ccs_arr_IN->used() == 0) return;
      if (_capture_low && ccs_low->used() == 0) return;
      if (_capture_high && ccs_high->used() == 0) return;
      that->cpp_testbench_active.write(false);
      if (average_period > SC_ZERO_TIME && sc_time_stamp() != timeout)
         wait(average_period * 10, ccs_arr_IN->ok_to_put() | ccs_low->ok_to_put() | ccs_high->ok_to_put());
      else
         wait(ccs_arr_IN->ok_to_put() | ccs_low->ok_to_put() | ccs_high->ok_to_put());
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

void mc_testbench::capture_IN(int arr[64], int low, int high)
{
   that->capture_arr_IN(arr);
   that->capture_low(low);
   that->capture_high(high);
}
// ============================================
// Function: capture_OUT
// --------------------------------------------

void mc_testbench::capture_OUT(int arr[64], int low, int high)
{
   that->capture_arr(arr);
}
// ============================================
// Function: exec_quickSort
// --------------------------------------------

void mc_testbench::exec_quickSort(int arr[64], int low, int high)
{
   #ifndef CCS_SCVERIFY_USE_CCS_BLOCK
   wait_for_idle_sync();
   capture_IN(arr, low, high);
   quickSort(arr, low, high);
   // throttle ac_channel based on number of calls to chan::size() or chan::empty() or chan::nb_read() (but not chan::available()) 
   if (1) {
      int cnt=0;
      if (cnt) std::cout << "mc_testbench.cpp: CONTINUES @ " << sc_time_stamp() << std::endl;
      if (cnt) that->cpp_testbench_active.write(true);
   }
   capture_OUT(arr, low, high);
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
   
   if (!_capture_arr) {
      cout<<"'arr' - warning, output was optimized away"<<endl;
   } else {
      _num_outputs_checked++;
      _failed |= arr_comp->check_results(arr_capture_count,testbench::arr_skip_noerr);
      _has_capture_counts |= !!(arr_capture_count);
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
   if (arr_comp->get_compare_count() < arr_capture_count) {testbench_end_event.notify(1,SC_NS); return;}
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
   testbench::arr_ignore = false;
   testbench::arr_skip = false;
   testbench::arr_skip_quiet = false;
   testbench::arr_skip_once = false;
   testbench::arr_skip_noerr = false;
   testbench::arr_array_comp_first = -1;
   testbench::arr_array_comp_last = -1;
   testbench::arr_IN_wait_ctrl.clear();
   arr_IN_capture_count = 0;
   arr_IN_iteration_count = 0;
   testbench::arr_use_mask = false;
   testbench::arr_output_mask = (int) ~0;
   testbench::arr_wait_ctrl.clear();
   arr_capture_count = 0;
   arr_iteration_count = 0;
   testbench::low_ignore = false;
   testbench::low_skip = false;
   testbench::low_skip_quiet = false;
   testbench::low_skip_once = false;
   testbench::low_skip_noerr = false;
   testbench::low_array_comp_first = -1;
   testbench::low_array_comp_last = -1;
   testbench::low_wait_ctrl.clear();
   low_capture_count = 0;
   low_iteration_count = 0;
   testbench::high_ignore = false;
   testbench::high_skip = false;
   testbench::high_skip_quiet = false;
   testbench::high_skip_once = false;
   testbench::high_skip_noerr = false;
   testbench::high_array_comp_first = -1;
   testbench::high_array_comp_last = -1;
   testbench::high_wait_ctrl.clear();
   high_capture_count = 0;
   high_iteration_count = 0;
   testbench testbench_inst(sc_argc(), sc_argv());
   main_exit_code = testbench_inst.main();
   cout<<"Info: Execution of user-supplied C++ testbench 'main()' has completed with exit code = " << main_exit_code << endl;
   cout<<endl;
   cout<<"Info: Collecting data completed"<<endl;
   cout<<"   captured "<<arr_IN_capture_count<<" values of arr_IN"<<endl;
   cout<<"   captured "<<arr_capture_count<<" values of arr"<<endl;
   cout<<"   captured "<<low_capture_count<<" values of low"<<endl;
   cout<<"   captured "<<high_capture_count<<" values of high"<<endl;
   testbench_ended = true;
   testbench_end_event.notify(SC_ZERO_TIME);
}
#ifdef CCS_SCVERIFY_USE_CCS_BLOCK
#include "ccs_block_macros.cpp"
#endif
