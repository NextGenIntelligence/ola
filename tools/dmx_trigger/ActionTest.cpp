/*
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 * ActionTest.cpp
 * Test fixture for the Action classes
 * Copyright (C) 2011 Simon Newton
 */

#include <cppunit/extensions/HelperMacros.h>
#include <string>

#include "tools/dmx_trigger/Action.h"


class ActionTest: public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(ActionTest);
  CPPUNIT_TEST(testVariableAssignmentAction);
  CPPUNIT_TEST_SUITE_END();

  public:
    void testVariableAssignmentAction();
};


CPPUNIT_TEST_SUITE_REGISTRATION(ActionTest);


/*
 * Check that the VariableAssignmentActions work.
 */
void ActionTest::testVariableAssignmentAction() {
  const string VARIABLE_ONE = "one";
  const string FOO_VALUE = "foo";
  const string BAR_VALUE = "bar";

  Context context;
  string value;
  CPPUNIT_ASSERT(!context.Lookup(VARIABLE_ONE, &value));

  // trigger the action
  VariableAssignmentAction action(VARIABLE_ONE, FOO_VALUE);
  action.Execute(&context, 0);

  // check the context has updated
  CPPUNIT_ASSERT(context.Lookup(VARIABLE_ONE, &value));
  CPPUNIT_ASSERT_EQUAL(FOO_VALUE, value);

  // another action
  VariableAssignmentAction action2(VARIABLE_ONE, BAR_VALUE);
  action2.Execute(&context, 0);

  CPPUNIT_ASSERT(context.Lookup(VARIABLE_ONE, &value));
  CPPUNIT_ASSERT_EQUAL(BAR_VALUE, value);
}