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


// Header for CMDNPromptDialog class

#ifndef __CMDNPROMPTDIALOG__MULBERRY__
#define __CMDNPROMPTDIALOG__MULBERRY__

#include <LDialogBox.h>

#include "cdstring.h"

// Constants

// Panes
const	PaneIDT		paneid_MDNPromptDialog = 2013;
const	PaneIDT		paneid_MDNPromptAddress = 'ADDR';
const	PaneIDT		paneid_MDNPromptSave = 'SAVE';

// Messages

// Resources
const	ResIDT		RidL_CMDNPromptDialogBtns = 2013;

// Classes
class LCheckBox;
class CStaticText;

class CMDNPromptDialog : public LDialogBox
{
public:
	enum { class_ID = 'MdnD' };

					CMDNPromptDialog();
					CMDNPromptDialog(LStream *inStream);
	virtual 		~CMDNPromptDialog();

	static bool PoseDialog(const cdstring& addr);

	void	SetDetails(const cdstring& addr);						// Set the dialogs info
	void	GetDetails(bool& save);									// Set the dialogs return info

protected:
	virtual void	FinishCreateSelf();								// Do odds & ends

private:
	CStaticText*	mAddress;
	LCheckBox*		mSave;
};

#endif
