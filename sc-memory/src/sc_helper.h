/*
-----------------------------------------------------------------------------
This source file is part of OSTIS (Open Semantic Technology for Intelligent Systems)
For the latest info, see http://www.ostis.net

Copyright (c) 2012 OSTIS

OSTIS is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

OSTIS is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with OSTIS.  If not, see <http://www.gnu.org/licenses/>.
-----------------------------------------------------------------------------
*/

#ifndef _sc_helper_h_
#define _sc_helper_h_

#include "sc_memory.h"

//! Enumeration of sc-keynodes
enum _sc_keynode
{
    SC_KEYNODE_NREL_SYSTEM_IDENTIFIER = 0,      // nrel_system_identifier
    SC_KEYNODE_COUNT
};

typedef enum _sc_keynode sc_keynode;


/*! Initialize helper.
 * @remarks Need to be called once at the beginning of sc-helper usage
 * @return If sc-helper initialized without any errors, then return SC_OK;
 * otherwise returns SC_ERROR
 */
sc_result sc_helper_init();

/*! Shuts down sc-helper.
 * @remarks This function need to be called once at the end of sc-helper usage
 */
void sc_helper_shutdown();

/*! Finds sc-addr of element with specified system identifier
 * @param data Buffer that contains system identifier for sc-element (must be an UTF-8 encoded)
 * @param len Length of data buffer
 * @param result_addr Pointer to result container
 * @return If sc-element with spefcified system identifier founded, then return SC_OK and result_addr
 * contains sc-addr of this one; otherwise return SC_ERROR. If there are more then one sc-elements with
 * specified system identifier, then return SC_ERROR_INVALID_STATE, but result_addr will contains sc-addr
 * of firstly founded sc-element.
 */
sc_result sc_helper_find_element_by_system_identifier(sc_char* data, sc_uint32 len, sc_addr *result_addr);

/*! Setup new system identifier for specified sc-element
 * @param addr sc-addr of sc-element to setup new system identifier
 * @param data Buffer that contains system identifier for sc-element (must be an UTF-8 encoded)
 * @param len Length of data buffer
 * @remarks If sc-element already has system identifier, then it would be replaced. If system identifier
 * already used for another sc-element, then function returns SC_ERROR_INVALID_PARAMS
 */
sc_result sc_helper_set_system_identifier(sc_addr addr, sc_char* data, sc_uint32 len);

/*! Returns sc-addr of specified sc-keynode
 * @param keynode Code of specified sc-keynode
 * @param keynode_addr Pointer to structure, that contains keynode sc-addr
 * @return If specified keynode exist, then return SC_OK and keynode_addr contains sc-addr of this one;
 * otherwise return SC_ERROR
 */
sc_result sc_helper_get_keynode(sc_keynode keynode, sc_addr *keynode_addr);

#endif // IDENTIFICATION_H
