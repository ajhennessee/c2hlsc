// ----------------------------------------------------------------------
//  HLS HDL:        Verilog Netlister
//  HLS Version:    2023.1_2/1049935 Production Release
//  HLS Date:       Sat Jun 10 10:53:51 PDT 2023
// 
//  Generated by:   lc4976@hansolo.poly.edu
//  Generated date: Tue Apr  9 23:33:06 2024
// ----------------------------------------------------------------------

// 
// ------------------------------------------------------------------
//  Design Unit:    SubBytes_core_core_fsm
//  FSM Module
// ------------------------------------------------------------------


module SubBytes_core_core_fsm (
  clk, rst_n, fsm_output, for_for_C_1_tr0, for_C_0_tr0
);
  input clk;
  input rst_n;
  output [4:0] fsm_output;
  reg [4:0] fsm_output;
  input for_for_C_1_tr0;
  input for_C_0_tr0;


  // FSM State Type Declaration for SubBytes_core_core_fsm_1
  parameter
    main_C_0 = 3'd0,
    for_for_C_0 = 3'd1,
    for_for_C_1 = 3'd2,
    for_C_0 = 3'd3,
    main_C_1 = 3'd4;

  reg [2:0] state_var;
  reg [2:0] state_var_NS;


  // Interconnect Declarations for Component Instantiations 
  always @(*)
  begin : SubBytes_core_core_fsm_1
    case (state_var)
      for_for_C_0 : begin
        fsm_output = 5'b00010;
        state_var_NS = for_for_C_1;
      end
      for_for_C_1 : begin
        fsm_output = 5'b00100;
        if ( for_for_C_1_tr0 ) begin
          state_var_NS = for_C_0;
        end
        else begin
          state_var_NS = for_for_C_0;
        end
      end
      for_C_0 : begin
        fsm_output = 5'b01000;
        if ( for_C_0_tr0 ) begin
          state_var_NS = main_C_1;
        end
        else begin
          state_var_NS = for_for_C_0;
        end
      end
      main_C_1 : begin
        fsm_output = 5'b10000;
        state_var_NS = main_C_0;
      end
      // main_C_0
      default : begin
        fsm_output = 5'b00001;
        state_var_NS = for_for_C_0;
      end
    endcase
  end

  always @(posedge clk) begin
    if ( ~ rst_n ) begin
      state_var <= main_C_0;
    end
    else begin
      state_var <= state_var_NS;
    end
  end

endmodule

// ------------------------------------------------------------------
//  Design Unit:    SubBytes_core
// ------------------------------------------------------------------


module SubBytes_core (
  clk, rst_n, state_rsc_zout, state_rsc_lzout, state_rsc_zin, state_triosy_lz
);
  input clk;
  input rst_n;
  output [127:0] state_rsc_zout;
  output state_rsc_lzout;
  input [127:0] state_rsc_zin;
  output state_triosy_lz;


  // Interconnect Declarations
  wire [127:0] state_rsci_din;
  reg state_triosy_obj_ld;
  wire [4:0] fsm_output;
  wire or_dcpl_2;
  wire or_dcpl_3;
  wire or_dcpl_5;
  wire or_dcpl_7;
  wire or_dcpl_9;
  wire or_dcpl_10;
  wire or_dcpl_15;
  wire or_dcpl_20;
  reg [1:0] i_2_0_sva_1_0;
  reg [1:0] j_2_0_sva_1_0;
  wire i_or_cse;
  wire [2:0] z_out;
  wire [3:0] nl_z_out;
  wire [7:0] ROM_1i8_1o8_ec965ae3708891513d2041cf4eab49d42f_1;

  wire i_not_1_nl;
  wire i_not_nl;
  wire[1:0] for_for_mux_18_nl;

  // Interconnect Declarations for Component Instantiations 
  wire  nl_state_rsci_ldout;
  assign nl_state_rsci_ldout = fsm_output[1];
  wire[7:0] for_for_mux_15_nl;
  wire or_25_nl;
  wire[7:0] for_for_mux_14_nl;
  wire or_24_nl;
  wire[7:0] for_for_mux_13_nl;
  wire or_23_nl;
  wire[7:0] for_for_mux_12_nl;
  wire or_22_nl;
  wire[7:0] for_for_mux_11_nl;
  wire or_20_nl;
  wire[7:0] for_for_mux_10_nl;
  wire or_19_nl;
  wire[7:0] for_for_mux_9_nl;
  wire or_18_nl;
  wire[7:0] for_for_mux_8_nl;
  wire or_17_nl;
  wire[7:0] for_for_mux_7_nl;
  wire or_15_nl;
  wire[7:0] for_for_mux_6_nl;
  wire or_14_nl;
  wire[7:0] for_for_mux_5_nl;
  wire or_13_nl;
  wire[7:0] for_for_mux_4_nl;
  wire or_12_nl;
  wire[7:0] for_for_mux_3_nl;
  wire or_9_nl;
  wire[7:0] for_for_mux_2_nl;
  wire or_7_nl;
  wire[7:0] for_for_mux_1_nl;
  wire or_5_nl;
  wire[7:0] for_for_mux_nl;
  wire for_for_nor_nl;
  wire [127:0] nl_state_rsci_dout;
  assign or_25_nl = or_dcpl_20 | or_dcpl_7;
  assign for_for_mux_15_nl = MUX_v_8_2_2(ROM_1i8_1o8_ec965ae3708891513d2041cf4eab49d42f_1,
      (state_rsci_din[127:120]), or_25_nl);
  assign or_24_nl = or_dcpl_20 | or_dcpl_5;
  assign for_for_mux_14_nl = MUX_v_8_2_2(ROM_1i8_1o8_ec965ae3708891513d2041cf4eab49d42f_1,
      (state_rsci_din[119:112]), or_24_nl);
  assign or_23_nl = or_dcpl_20 | or_dcpl_2;
  assign for_for_mux_13_nl = MUX_v_8_2_2(ROM_1i8_1o8_ec965ae3708891513d2041cf4eab49d42f_1,
      (state_rsci_din[111:104]), or_23_nl);
  assign or_22_nl = or_dcpl_20 | or_dcpl_9;
  assign for_for_mux_12_nl = MUX_v_8_2_2(ROM_1i8_1o8_ec965ae3708891513d2041cf4eab49d42f_1,
      (state_rsci_din[103:96]), or_22_nl);
  assign or_20_nl = or_dcpl_15 | or_dcpl_7;
  assign for_for_mux_11_nl = MUX_v_8_2_2(ROM_1i8_1o8_ec965ae3708891513d2041cf4eab49d42f_1,
      (state_rsci_din[95:88]), or_20_nl);
  assign or_19_nl = or_dcpl_15 | or_dcpl_5;
  assign for_for_mux_10_nl = MUX_v_8_2_2(ROM_1i8_1o8_ec965ae3708891513d2041cf4eab49d42f_1,
      (state_rsci_din[87:80]), or_19_nl);
  assign or_18_nl = or_dcpl_15 | or_dcpl_2;
  assign for_for_mux_9_nl = MUX_v_8_2_2(ROM_1i8_1o8_ec965ae3708891513d2041cf4eab49d42f_1,
      (state_rsci_din[79:72]), or_18_nl);
  assign or_17_nl = or_dcpl_15 | or_dcpl_9;
  assign for_for_mux_8_nl = MUX_v_8_2_2(ROM_1i8_1o8_ec965ae3708891513d2041cf4eab49d42f_1,
      (state_rsci_din[71:64]), or_17_nl);
  assign or_15_nl = or_dcpl_10 | or_dcpl_7;
  assign for_for_mux_7_nl = MUX_v_8_2_2(ROM_1i8_1o8_ec965ae3708891513d2041cf4eab49d42f_1,
      (state_rsci_din[63:56]), or_15_nl);
  assign or_14_nl = or_dcpl_10 | or_dcpl_5;
  assign for_for_mux_6_nl = MUX_v_8_2_2(ROM_1i8_1o8_ec965ae3708891513d2041cf4eab49d42f_1,
      (state_rsci_din[55:48]), or_14_nl);
  assign or_13_nl = or_dcpl_10 | or_dcpl_2;
  assign for_for_mux_5_nl = MUX_v_8_2_2(ROM_1i8_1o8_ec965ae3708891513d2041cf4eab49d42f_1,
      (state_rsci_din[47:40]), or_13_nl);
  assign or_12_nl = or_dcpl_10 | or_dcpl_9;
  assign for_for_mux_4_nl = MUX_v_8_2_2(ROM_1i8_1o8_ec965ae3708891513d2041cf4eab49d42f_1,
      (state_rsci_din[39:32]), or_12_nl);
  assign or_9_nl = or_dcpl_3 | or_dcpl_7;
  assign for_for_mux_3_nl = MUX_v_8_2_2(ROM_1i8_1o8_ec965ae3708891513d2041cf4eab49d42f_1,
      (state_rsci_din[31:24]), or_9_nl);
  assign or_7_nl = or_dcpl_3 | or_dcpl_5;
  assign for_for_mux_2_nl = MUX_v_8_2_2(ROM_1i8_1o8_ec965ae3708891513d2041cf4eab49d42f_1,
      (state_rsci_din[23:16]), or_7_nl);
  assign or_5_nl = or_dcpl_3 | or_dcpl_2;
  assign for_for_mux_1_nl = MUX_v_8_2_2(ROM_1i8_1o8_ec965ae3708891513d2041cf4eab49d42f_1,
      (state_rsci_din[15:8]), or_5_nl);
  assign for_for_nor_nl = ~(((i_2_0_sva_1_0[0]) & (~((j_2_0_sva_1_0!=2'b00) | (i_2_0_sva_1_0[1]))))
      | ((i_2_0_sva_1_0[1]) & (~((j_2_0_sva_1_0!=2'b00) | (i_2_0_sva_1_0[0])))) |
      ((i_2_0_sva_1_0==2'b11) & (j_2_0_sva_1_0==2'b00)) | ((j_2_0_sva_1_0[0]) & (~((j_2_0_sva_1_0[1])
      | (i_2_0_sva_1_0!=2'b00)))) | ((j_2_0_sva_1_0[0]) & (i_2_0_sva_1_0[0]) & (~((j_2_0_sva_1_0[1])
      | (i_2_0_sva_1_0[1])))) | ((j_2_0_sva_1_0[0]) & (i_2_0_sva_1_0[1]) & (~((j_2_0_sva_1_0[1])
      | (i_2_0_sva_1_0[0])))) | ((j_2_0_sva_1_0[0]) & (i_2_0_sva_1_0==2'b11) & (~
      (j_2_0_sva_1_0[1]))) | ((j_2_0_sva_1_0[1]) & (~((j_2_0_sva_1_0[0]) | (i_2_0_sva_1_0!=2'b00))))
      | ((j_2_0_sva_1_0[1]) & (i_2_0_sva_1_0[0]) & (~((j_2_0_sva_1_0[0]) | (i_2_0_sva_1_0[1]))))
      | ((j_2_0_sva_1_0[1]) & (i_2_0_sva_1_0[1]) & (~((j_2_0_sva_1_0[0]) | (i_2_0_sva_1_0[0]))))
      | ((j_2_0_sva_1_0[1]) & (i_2_0_sva_1_0==2'b11) & (~ (j_2_0_sva_1_0[0]))) |
      ((j_2_0_sva_1_0==2'b11) & (i_2_0_sva_1_0==2'b00)) | ((j_2_0_sva_1_0==2'b11)
      & (i_2_0_sva_1_0==2'b01)) | ((j_2_0_sva_1_0==2'b11) & (i_2_0_sva_1_0==2'b10))
      | ((j_2_0_sva_1_0==2'b11) & (i_2_0_sva_1_0==2'b11)));
  assign for_for_mux_nl = MUX_v_8_2_2((state_rsci_din[7:0]), ROM_1i8_1o8_ec965ae3708891513d2041cf4eab49d42f_1,
      for_for_nor_nl);
  assign nl_state_rsci_dout = {for_for_mux_15_nl , for_for_mux_14_nl , for_for_mux_13_nl
      , for_for_mux_12_nl , for_for_mux_11_nl , for_for_mux_10_nl , for_for_mux_9_nl
      , for_for_mux_8_nl , for_for_mux_7_nl , for_for_mux_6_nl , for_for_mux_5_nl
      , for_for_mux_4_nl , for_for_mux_3_nl , for_for_mux_2_nl , for_for_mux_1_nl
      , for_for_mux_nl};
  wire [7:0] nl_U_ROM_1i8_1o8_ec965ae3708891513d2041cf4eab49d42f_rg_I_1;
  assign nl_U_ROM_1i8_1o8_ec965ae3708891513d2041cf4eab49d42f_rg_I_1 = MUX_v_8_16_2((state_rsci_din[7:0]),
      (state_rsci_din[15:8]), (state_rsci_din[23:16]), (state_rsci_din[31:24]), (state_rsci_din[39:32]),
      (state_rsci_din[47:40]), (state_rsci_din[55:48]), (state_rsci_din[63:56]),
      (state_rsci_din[71:64]), (state_rsci_din[79:72]), (state_rsci_din[87:80]),
      (state_rsci_din[95:88]), (state_rsci_din[103:96]), (state_rsci_din[111:104]),
      (state_rsci_din[119:112]), (state_rsci_din[127:120]), {j_2_0_sva_1_0 , i_2_0_sva_1_0});
  wire  nl_SubBytes_core_core_fsm_inst_for_for_C_1_tr0;
  assign nl_SubBytes_core_core_fsm_inst_for_for_C_1_tr0 = z_out[2];
  wire  nl_SubBytes_core_core_fsm_inst_for_C_0_tr0;
  assign nl_SubBytes_core_core_fsm_inst_for_C_0_tr0 = z_out[2];
  mgc_inout_prereg_en_v1 #(.rscid(32'sd1),
  .width(32'sd128)) state_rsci (
      .din(state_rsci_din),
      .ldout(nl_state_rsci_ldout),
      .dout(nl_state_rsci_dout[127:0]),
      .zin(state_rsc_zin),
      .lzout(state_rsc_lzout),
      .zout(state_rsc_zout)
    );
  mgc_io_sync_v2 #(.valid(32'sd0)) state_triosy_obj (
      .ld(state_triosy_obj_ld),
      .lz(state_triosy_lz)
    );
  ROM_1i8_1o8_6cd8ed6ecb89da3c4ea51c9925c1afffbc  U_ROM_1i8_1o8_ec965ae3708891513d2041cf4eab49d42f_rg
      (
      .I_1(nl_U_ROM_1i8_1o8_ec965ae3708891513d2041cf4eab49d42f_rg_I_1[7:0]),
      .O_1(ROM_1i8_1o8_ec965ae3708891513d2041cf4eab49d42f_1)
    );
  SubBytes_core_core_fsm SubBytes_core_core_fsm_inst (
      .clk(clk),
      .rst_n(rst_n),
      .fsm_output(fsm_output),
      .for_for_C_1_tr0(nl_SubBytes_core_core_fsm_inst_for_for_C_1_tr0),
      .for_C_0_tr0(nl_SubBytes_core_core_fsm_inst_for_C_0_tr0)
    );
  assign i_or_cse = (fsm_output[0]) | (fsm_output[3]);
  assign or_dcpl_2 = (i_2_0_sva_1_0!=2'b01);
  assign or_dcpl_3 = (j_2_0_sva_1_0!=2'b00);
  assign or_dcpl_5 = (i_2_0_sva_1_0!=2'b10);
  assign or_dcpl_7 = ~((i_2_0_sva_1_0==2'b11));
  assign or_dcpl_9 = (i_2_0_sva_1_0!=2'b00);
  assign or_dcpl_10 = (j_2_0_sva_1_0!=2'b01);
  assign or_dcpl_15 = (j_2_0_sva_1_0!=2'b10);
  assign or_dcpl_20 = ~((j_2_0_sva_1_0==2'b11));
  always @(posedge clk) begin
    if ( ~ rst_n ) begin
      i_2_0_sva_1_0 <= 2'b00;
    end
    else if ( i_or_cse ) begin
      i_2_0_sva_1_0 <= MUX_v_2_2_2(2'b00, (z_out[1:0]), i_not_1_nl);
    end
  end
  always @(posedge clk) begin
    if ( ~ rst_n ) begin
      j_2_0_sva_1_0 <= 2'b00;
    end
    else if ( (fsm_output[2]) | i_or_cse ) begin
      j_2_0_sva_1_0 <= MUX_v_2_2_2(2'b00, (z_out[1:0]), i_not_nl);
    end
  end
  always @(posedge clk) begin
    if ( ~ rst_n ) begin
      state_triosy_obj_ld <= 1'b0;
    end
    else begin
      state_triosy_obj_ld <= (z_out[2]) & (fsm_output[3]);
    end
  end
  assign i_not_1_nl = ~ (fsm_output[0]);
  assign i_not_nl = ~ i_or_cse;
  assign for_for_mux_18_nl = MUX_v_2_2_2(j_2_0_sva_1_0, i_2_0_sva_1_0, fsm_output[3]);
  assign nl_z_out = conv_u2u_2_3(for_for_mux_18_nl) + 3'b001;
  assign z_out = nl_z_out[2:0];

  function automatic [1:0] MUX_v_2_2_2;
    input [1:0] input_0;
    input [1:0] input_1;
    input  sel;
    reg [1:0] result;
  begin
    case (sel)
      1'b0 : begin
        result = input_0;
      end
      default : begin
        result = input_1;
      end
    endcase
    MUX_v_2_2_2 = result;
  end
  endfunction


  function automatic [7:0] MUX_v_8_16_2;
    input [7:0] input_0;
    input [7:0] input_1;
    input [7:0] input_2;
    input [7:0] input_3;
    input [7:0] input_4;
    input [7:0] input_5;
    input [7:0] input_6;
    input [7:0] input_7;
    input [7:0] input_8;
    input [7:0] input_9;
    input [7:0] input_10;
    input [7:0] input_11;
    input [7:0] input_12;
    input [7:0] input_13;
    input [7:0] input_14;
    input [7:0] input_15;
    input [3:0] sel;
    reg [7:0] result;
  begin
    case (sel)
      4'b0000 : begin
        result = input_0;
      end
      4'b0001 : begin
        result = input_1;
      end
      4'b0010 : begin
        result = input_2;
      end
      4'b0011 : begin
        result = input_3;
      end
      4'b0100 : begin
        result = input_4;
      end
      4'b0101 : begin
        result = input_5;
      end
      4'b0110 : begin
        result = input_6;
      end
      4'b0111 : begin
        result = input_7;
      end
      4'b1000 : begin
        result = input_8;
      end
      4'b1001 : begin
        result = input_9;
      end
      4'b1010 : begin
        result = input_10;
      end
      4'b1011 : begin
        result = input_11;
      end
      4'b1100 : begin
        result = input_12;
      end
      4'b1101 : begin
        result = input_13;
      end
      4'b1110 : begin
        result = input_14;
      end
      default : begin
        result = input_15;
      end
    endcase
    MUX_v_8_16_2 = result;
  end
  endfunction


  function automatic [7:0] MUX_v_8_2_2;
    input [7:0] input_0;
    input [7:0] input_1;
    input  sel;
    reg [7:0] result;
  begin
    case (sel)
      1'b0 : begin
        result = input_0;
      end
      default : begin
        result = input_1;
      end
    endcase
    MUX_v_8_2_2 = result;
  end
  endfunction


  function automatic [2:0] conv_u2u_2_3 ;
    input [1:0]  vector ;
  begin
    conv_u2u_2_3 = {1'b0, vector};
  end
  endfunction

endmodule

// ------------------------------------------------------------------
//  Design Unit:    SubBytes
// ------------------------------------------------------------------


module SubBytes (
  clk, rst_n, state_rsc_zout, state_rsc_lzout, state_rsc_zin, state_triosy_lz
);
  input clk;
  input rst_n;
  output [127:0] state_rsc_zout;
  output state_rsc_lzout;
  input [127:0] state_rsc_zin;
  output state_triosy_lz;



  // Interconnect Declarations for Component Instantiations 
  SubBytes_core SubBytes_core_inst (
      .clk(clk),
      .rst_n(rst_n),
      .state_rsc_zout(state_rsc_zout),
      .state_rsc_lzout(state_rsc_lzout),
      .state_rsc_zin(state_rsc_zin),
      .state_triosy_lz(state_triosy_lz)
    );
endmodule



