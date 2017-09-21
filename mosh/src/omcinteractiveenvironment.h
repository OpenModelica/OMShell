/*
 * This file is part of OpenModelica.
 *
 * Copyright (c) 1998-2010, Linköpings University,
 * Department of Computer and Information Science,
 * SE-58183 Linköping, Sweden.
 *
 * All rights reserved.
 *
 * THIS PROGRAM IS PROVIDED UNDER THE TERMS OF THIS OSMC PUBLIC
 * LICENSE (OSMC-PL). ANY USE, REPRODUCTION OR DISTRIBUTION OF
 * THIS PROGRAM CONSTITUTES RECIPIENT'S ACCEPTANCE OF THE OSMC
 * PUBLIC LICENSE.
 *
 * The OpenModelica software and the Open Source Modelica
 * Consortium (OSMC) Public License (OSMC-PL) are obtained
 * from Linköpings University, either from the above address,
 * from the URL: http://www.ida.liu.se/projects/OpenModelica
 * and in the OpenModelica distribution.
 *
 * This program is distributed  WITHOUT ANY WARRANTY; without
 * even the implied warranty of  MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE, EXCEPT AS EXPRESSLY SET FORTH
 * IN THE BY RECIPIENT SELECTED SUBSIDIARY LICENSE CONDITIONS
 * OF OSMC-PL.
 *
 * See the full OSMC Public License conditions for more details.
 *
 * For more information about the Qt-library visit TrollTech's webpage
 * regarding the Qt licence: http://www.trolltech.com/products/qt/licensing.html
 */

#ifndef _OMCINTERACTIVE_H
#define _OMCINTERACTIVE_H

#include <string>
#include <sstream>
#include <iostream>

#include "meta/meta_modelica.h"

//using std::string;
using namespace std;

namespace IAEX
{
  class OmcInteractiveEnvironment
  {
  private:
    OmcInteractiveEnvironment();
    virtual ~OmcInteractiveEnvironment();

  public:
    threadData_t *threadData_;
    void *symbolTable_;

    static OmcInteractiveEnvironment* getInstance();
    virtual string getResult();
    virtual string getError();
    virtual int getErrorLevel();
    virtual void evalExpression(const string expr);
    static string OMCVersion();
    static string OpenModelicaHome();
    static string TmpPath();

  private:
    static OmcInteractiveEnvironment* selfInstance;
    string result_;
    string error_;
    int severity;
  };
}
#endif
