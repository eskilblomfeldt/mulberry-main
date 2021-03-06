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


// Header for CSMTPView class

#ifndef __CSMTPVIEW__MULBERRY__
#define __CSMTPVIEW__MULBERRY__

#include "CGrayBackground.h"
#include "CMailboxView.h"
#include "CMailboxTitleTable.h"
#include "CSMTPTable.h"

// Classes
class CSMTPSender;

class CSMTPView : public CMailboxView
{
	friend class CSMTPTable;

public:
					CSMTPView();
	virtual 		~CSMTPView();

			void	SetSMTPSender(CSMTPSender* sender);
	CSMTPSender*	GetSMTPSender()
		{ return mSender; }

	virtual void	MakeToolbars(CToolbarView* parent);

	virtual void	DoProtocolLogoff(const CMboxProtocol* proto)
		{ }
	virtual void	DoRemoveWD(const CMboxList* wd)
		{ }

	virtual bool	TestClose()
		{ return true; }
	virtual void	DoClose();
	virtual void	DoCloseMbox();

	virtual void	ViewMbox(CMbox* anMbox,
						bool use_dynamic = true,
						bool is_search = false)				// Set the mbox for viewing
		{ }
	virtual void	SetMbox(CMbox* anMbox,					// Set the mbox
						bool is_search = false);
	virtual bool	Recycle(CMbox* anMbox,					// Recycle to new mbox
						bool is_search = false)
		{ return false; }
	virtual bool	Substitute(CMbox* anMbox,				// Substitute new mailbox
						bool select = true,
						bool is_search = false)
		{ return false; }

	virtual void	RenamedMailbox(const CMbox* mbox);		// Mailbox was renamed

			void	UpdateTitle();

			void	ResetConnection();

	virtual void	ResetState(bool force = false);			// Reset window state
	virtual void	SaveDefaultState(void);					// Save current state as default

protected:
	CMailboxTitleTable		mSMTPTitles;					// Cached titles
	CSMTPTable				mSMTPTable;						// Cached table
	CGrayBackground			mFooter;
	CStatic					mTotalText;

	CSMTPSender*	mSender;

	// message handlers
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy(void);

	DECLARE_MESSAGE_MAP()
};

#endif
