case TIME_DEVICE_CP_FIRST:
	if (TGW_Protect.IsBKOffSuccess(TGW_Protect.CP.GetProtectAcionState()))
	{
		switch (TGW_Protect.CP.GetProtectAcionState())
		{
		case ProtectAction_A:
			AppendText(IDC_EDIT_TEXT, _T("A相跳闸成功\r\n"));
			KillTimer(TIME_DEVICE_CP_THIRD);
			break;
		case ProtectAction_B:
			AppendText(IDC_EDIT_TEXT, _T("B相跳闸成功\r\n"));
			KillTimer(TIME_DEVICE_CP_THIRD);
			break;
		case ProtectAction_C:
			AppendText(IDC_EDIT_TEXT, _T("C相跳闸成功\r\n"));
			KillTimer(TIME_DEVICE_CP_THIRD);
			break;
		case ProtectNoAction:
			KillTimer(TIME_DEVICE_CP_FIRST);
			KillTimer(TIME_DEVICE_CP_SECOND);
			break;
		default:
			AppendText(IDC_EDIT_TEXT, _T("三相跳闸成功\r\n"));
			KillTimer(TIME_DEVICE_CP_THIRD);
			break;
		}
	}
	else
	{
		switch (TGW_Protect.CP.GetProtectAcionState())
		{
		case ProtectAction_A:
			AppendText(IDC_EDIT_TEXT, _T("A相单跳失败永跳\r\n"));
			TGW_Protect.BK.OffBKABC();
			UpdateBKState(TGW_Protect);
			TGW_Protect.CP.SetProtectActionState(ProtectAction_ABC);
			break;
		case ProtectAction_B:
			AppendText(IDC_EDIT_TEXT, _T("B相单跳失败永跳\r\n"));
			TGW_Protect.BK.OffBKABC();
			UpdateBKState(TGW_Protect);
			TGW_Protect.CP.SetProtectActionState(ProtectAction_ABC);
			break;
		case ProtectAction_C:
			AppendText(IDC_EDIT_TEXT, _T("C相单跳失败永跳\r\n"));
			TGW_Protect.BK.OffBKABC();
			UpdateBKState(TGW_Protect);
			TGW_Protect.CP.SetProtectActionState(ProtectAction_ABC);
			break;
		case ProtectNoAction:
			KillTimer(TIME_DEVICE_CP_FIRST);
			KillTimer(TIME_DEVICE_CP_SECOND);
			break;
		default:
			AppendText(IDC_EDIT_TEXT, _T("三相跳闸失败永跳\r\n"));
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
		AppendText(IDC_EDIT_TEXT, _T("永跳成功\r\n"));
		KillTimer(TIME_DEVICE_CP_THIRD);
	}
	else
	{

	}
	KillTimer(TIME_DEVICE_CP_SECOND);
	break;
case TIME_DEVICE_CP_THIRD:
	AppendText(IDC_EDIT_TEXT, _T("永跳失败\r\n"));
	KillTimer(TIME_DEVICE_CP_THIRD);
	break;