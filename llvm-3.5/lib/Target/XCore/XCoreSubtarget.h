//===-- XCoreSubtarget.h - Define Subtarget for the XCore -------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This file declares the XCore specific subclass of TargetSubtargetInfo.
//
//===----------------------------------------------------------------------===//

#ifndef XCORESUBTARGET_H
#define XCORESUBTARGET_H

#include "XCoreFrameLowering.h"
#include "XCoreISelLowering.h"
#include "XCoreInstrInfo.h"
#include "XCoreSelectionDAGInfo.h"
#include "llvm/IR/DataLayout.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetSubtargetInfo.h"
#include <string>

#define GET_SUBTARGETINFO_HEADER
#include "XCoreGenSubtargetInfo.inc"

namespace llvm {
class StringRef;

class XCoreSubtarget : public XCoreGenSubtargetInfo {
  virtual void anchor();
  const DataLayout DL;       // Calculates type size & alignment
  XCoreInstrInfo InstrInfo;
  XCoreFrameLowering FrameLowering;
  XCoreTargetLowering TLInfo;
  XCoreSelectionDAGInfo TSInfo;

public:
  /// This constructor initializes the data members to match that
  /// of the specified triple.
  ///
  XCoreSubtarget(const std::string &TT, const std::string &CPU,
                 const std::string &FS, const TargetMachine &TM);
  
  /// ParseSubtargetFeatures - Parses features string setting specified 
  /// subtarget options.  Definition of function is auto generated by tblgen.
  void ParseSubtargetFeatures(StringRef CPU, StringRef FS);

  const XCoreInstrInfo *getInstrInfo() const { return &InstrInfo; }
  const XCoreFrameLowering *getFrameLowering() const { return &FrameLowering; }
  const XCoreTargetLowering *getTargetLowering() const { return &TLInfo; }
  const XCoreSelectionDAGInfo *getSelectionDAGInfo() const { return &TSInfo; }
  const TargetRegisterInfo *getRegisterInfo() const {
    return &InstrInfo.getRegisterInfo();
  }
  const DataLayout *getDataLayout() const { return &DL; }
};
} // End llvm namespace

#endif