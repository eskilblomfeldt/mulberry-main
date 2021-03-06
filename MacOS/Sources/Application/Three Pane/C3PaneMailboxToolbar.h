/*
    Copyright (c) 2007 Cyrus Daboo. All rights reserved.
    
    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at
    
        http://www.apache.org/licenses/LICENSE-2.0
    
    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/


// Header for C3PaneMailboxToolbar class

#ifndef __C3PANEMAILBOXTOOLBAR__MULBERRY__
#define __C3PANEMAILBOXTOOLBAR__MULBERRY__

#include "CToolbar.h"

// Constants
const	PaneIDT		paneid_3PaneMailboxToolbar = 1750;

// Resources
const	ResIDT		RidL_C3PaneMailboxToolbar = 1750;

// Classes
class CMailboxToolbarPopup;

class C3PaneMailboxToolbar : public CToolbar
{
public:
	enum { class_ID = 'TB31' };

					C3PaneMailboxToolbar();
					C3PaneMailboxToolbar(LStream *inStream);
	virtual 		~C3PaneMailboxToolbar();

	CMailboxToolbarPopup*	GetCopyBtn() const;

protected:

	virtual void	FinishCreateSelf(void);
};

#endif
