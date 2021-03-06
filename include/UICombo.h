#ifndef __UICOMBO_H__
#define __UICOMBO_H__

namespace duisharp {
	/////////////////////////////////////////////////////////////////////////////////////
	//

	class CComboWnd;
	class IUIComboEdit;

	class DUISHARP_API CUICombo : public CUIContainer, public IUIListOwner
	{
		friend CComboWnd;
		friend IUIComboEdit;
	public:
		CUICombo();

		LPCTSTR GetClass() const;
		LPVOID GetInterface(LPCTSTR pstrName);

		virtual void CreateEdit();
		virtual void DestroyEdit();
		virtual RECT CalEditPos();

		virtual void CloseDropBox();

		void DoInit();
		UINT GetControlFlags() const;

		CStdString GetText() const;
		void SetEnabled(bool bEnable = true);

		CStdString GetDropBoxAttributeList();
		void SetDropBoxAttributeList(LPCTSTR pstrList);
		SIZE GetDropBoxSize() const;
		void SetDropBoxSize(SIZE szDropBox);
		bool IsDropList() const;
		void SetDropList(bool bDropList);

		int GetCurSel() const;  
		bool SelectItem(int iIndex, bool bTakeFocus = false);

		bool SetItemIndex(CUIControl* pControl, int iIndex);
		bool Add(CUIControl* pControl);
		bool AddAt(CUIControl* pControl, int iIndex);
		bool Remove(CUIControl* pControl);
		bool RemoveAt(int iIndex);
		void RemoveAll();

		bool Activate();
		
		void SetNativeEditBkColor(DWORD dwBkColor);
		DWORD GetNativeEditBkColor() const;

		void SetComposited(bool bComposited);
		bool IsComposited() const;

		TUIListInfo* GetListInfo();
		void SetItemFont(LPCTSTR pstrFont);
		UINT GetItemTextStyle() const;
		void SetItemTextStyle(UINT uStyle);
		RECT GetItemTextPadding() const;
		void SetItemTextPadding(RECT rc);
		DWORD GetItemTextColor() const;
		void SetItemTextColor(DWORD dwTextColor);
		DWORD GetItemBkColor() const;
		void SetItemBkColor(DWORD dwBkColor);
		LPCTSTR GetItemBkImage() const;
		void SetItemBkImage(LPCTSTR pStrImage);
		bool IsAlternateBk() const;
		void SetAlternateBk(bool bAlternateBk);
		DWORD GetSelectedItemTextColor() const;
		void SetSelectedItemTextColor(DWORD dwTextColor);
		DWORD GetSelectedItemBkColor() const;
		void SetSelectedItemBkColor(DWORD dwBkColor);
		LPCTSTR GetSelectedItemImage() const;
		void SetSelectedItemImage(LPCTSTR pStrImage);
		DWORD GetHotItemTextColor() const;
		void SetHotItemTextColor(DWORD dwTextColor);
		DWORD GetHotItemBkColor() const;
		void SetHotItemBkColor(DWORD dwBkColor);
		LPCTSTR GetHotItemImage() const;
		void SetHotItemImage(LPCTSTR pStrImage);
		DWORD GetDisabledItemTextColor() const;
		void SetDisabledItemTextColor(DWORD dwTextColor);
		DWORD GetDisabledItemBkColor() const;
		void SetDisabledItemBkColor(DWORD dwBkColor);
		LPCTSTR GetDisabledItemImage() const;
		void SetDisabledItemImage(LPCTSTR pStrImage);
		DWORD GetItemLineColor() const;
		void SetItemLineColor(DWORD dwLineColor);
		bool IsItemShowHtml();
		void SetItemShowHtml(bool bShowHtml = true);

		SIZE EstimateSize(SIZE szAvailable, bool bSized = true);
		void SetPos(RECT rc);
		void DoEvent(TUIEvent& event);
		void SetAttribute(LPCTSTR pstrName, LPCTSTR pstrValue);
		void DoPaint(HDC hDC, const RECT& rcPaint, UINT uType = 0);
		void PaintText(HDC hDC);

	protected:
		CComboWnd* m_pWindow;
		IUIComboEdit* m_pEdit;

		bool m_bComposited;
		bool m_bDropList;
		int m_iCurSel;
		SIZE m_szDropBox;
		DWORD m_dwEditbkColor;
		CStdString m_sDropBoxAttributes;

		TUIListInfo m_ListInfo;
	};
	
	class IUIComboEdit
	{
	public:
		IUIComboEdit();
		~IUIComboEdit();

	public:
		virtual void Init(CUICombo* pOwner) = 0;
		virtual BOOL InitBegin(CUICombo* pOwner);
		virtual void InitEnd();
		virtual HWND GetEditWnd() = 0;
		virtual BOOL IsWindow();
		virtual RECT CalPos();
		virtual void SetSelAll();
		virtual LRESULT HandleMessage(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		virtual LRESULT OnKeyMsg(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		virtual LRESULT OnChar(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		virtual LRESULT OnSetFocus(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		virtual LRESULT OnKillFocus(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		virtual LRESULT OnEditChanged(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
		virtual LRESULT OnCtrlColor(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

	protected:
		BOOL m_bInit;
		CUICombo* m_pOwner;
		HBRUSH m_hBkBrush;
		HWND m_hParent;
		UINT m_uStyle;
		RECT m_rcItem;
	};
} // namespace duisharp

#endif // __UICOMBO_H__
