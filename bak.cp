case TIME_DEVICE_CP_FIRST:
	if (TGW_Protect.IsBKOffSuccess(TGW_Protect.CP.GetProtectAcionState()))
	{
		switch (TGW_Protect.CP.GetProtectAcionState())
		{
		case ProtectAction_A:
			AppendText(IDC_EDIT_TEXT, _T("A����բ�ɹ�\r\n"));
			KillTimer(TIME_DEVICE_CP_THIRD);
			break;
		case ProtectAction_B:
			AppendText(IDC_EDIT_TEXT, _T("B����բ�ɹ�\r\n"));
			KillTimer(TIME_DEVICE_CP_THIRD);
			break;
		case ProtectAction_C:
			AppendText(IDC_EDIT_TEXT, _T("C����բ�ɹ�\r\n"));
			KillTimer(TIME_DEVICE_CP_THIRD);
			break;
		case ProtectNoAction:
			KillTimer(TIME_DEVICE_CP_FIRST);
			KillTimer(TIME_DEVICE_CP_SECOND);
			break;
		default:
			AppendText(IDC_EDIT_TEXT, _T("������բ�ɹ�\r\n"));
			KillTimer(TIME_DEVICE_CP_THIRD);
			break;
		}
	}
	else
	{
		switch (TGW_Protect.CP.GetProtectAcionState())
		{
		case ProtectAction_A:
			AppendText(IDC_EDIT_TEXT, _T("A�൥��ʧ������\r\n"));
			TGW_Protect.BK.OffBKABC();
			UpdateBKState(TGW_Protect);
			TGW_Protect.CP.SetProtectActionState(ProtectAction_ABC);
			break;
		case ProtectAction_B:
			AppendText(IDC_EDIT_TEXT, _T("B�൥��ʧ������\r\n"));
			TGW_Protect.BK.OffBKABC();
			UpdateBKState(TGW_Protect);
			TGW_Protect.CP.SetProtectActionState(ProtectAction_ABC);
			break;
		case ProtectAction_C:
			AppendText(IDC_EDIT_TEXT, _T("C�൥��ʧ������\r\n"));
			TGW_Protect.BK.OffBKABC();
			UpdateBKState(TGW_Protect);
			TGW_Protect.CP.SetProtectActionState(ProtectAction_ABC);
			break;
		case ProtectNoAction:
			KillTimer(TIME_DEVICE_CP_FIRST);
			KillTimer(TIME_DEVICE_CP_SECOND);
			break;
		default:
			AppendText(IDC_EDIT_TEXT, _T("������բʧ������\r\n"));
			TGW_Protect.BK.OffBKABC();
			TGW_Protect.CP.SetProtectActionState(ProtectAction_ABC);
			break;
		}
	}
	KillTimer(TIME_DEVICE_CP_FIRST);
	break;
case TIME_DEVICE_CP_SECOND:
	if (TGW_Protect.IsBKOffSuccess(TGW_Protect.CP.GetProtectAcionState()))
	{
		AppendText(IDC_EDIT_TEXT, _T("�����ɹ�\r\n"));
		KillTimer(TIME_DEVICE_CP_THIRD);
	}
	else
	{

	}
	KillTimer(TIME_DEVICE_CP_SECOND);
	break;
case TIME_DEVICE_CP_THIRD:
	AppendText(IDC_EDIT_TEXT, _T("����ʧ��\r\n"));
	KillTimer(TIME_DEVICE_CP_THIRD);
	break;