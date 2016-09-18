/* easyMessage.inc
 *
 * (c) Copyright 2016, SecretBoss
 * This file is provided as is (no warranties).
 *
 * Custom SendClientMessage functions are not made by me
 * This script simple simplifies the way of sending messages
 * You can use formated/non-formated messaging on the original functions
 * 
 * Example:
 * SendClientMessage(playerid, -1, "SERVER: Your id is %i", playerid);
 * SendClientMessage(playerid, -1, "SERVER: welcome to server");
 *
 * Both of ways can be used (also in SendClientMessageToAll function)
 *
 * NOTE: File must be included in the top of the script before any other include
 */

#if defined _easymessage_included
  #endinput
#endif

#define _easymessage_included

#define SendClientMessage			EM__SendClientMessageEx
#define SendClientMessageToAll		EM__SendClientMessageToAllEx

// Emmet_
stock EM__SendClientMessageEx(playerid, color, const text[], {Float, _}:...)
{
	static
	    args,
	    str[144]
	;
	
	if ((args = numargs()) == 3)
	{
	    SendClientMessage(playerid, color, text);
	}
	else
	{
		while (--args >= 3)
		{
			#emit LCTRL 5
			#emit LOAD.alt args
			#emit SHL.C.alt 2
			#emit ADD.C 12
			#emit ADD
			#emit LOAD.I
			#emit PUSH.pri
		}
		#emit PUSH.S text
		#emit PUSH.C 144
		#emit PUSH.C str
		#emit PUSH.S 8
		#emit SYSREQ.C format
		#emit LCTRL 5
		#emit SCTRL 4

		SendClientMessage(playerid, color, str);

		#emit RETN
	}
	return 1;
}

// Emmet_
stock EM__SendClientMessageToAllEx(color, const text[], {Float, _}:...)
{
	new args, str[144];

	if((args = numargs()) == 2) SendClientMessageToAll(color, text);
	else
	{
		while (--args >= 2)
		{
			#emit LCTRL 5
			#emit LOAD.alt args
			#emit SHL.C.alt 2
			#emit ADD.C 12
			#emit ADD
			#emit LOAD.I
			#emit PUSH.pri
		}
		#emit PUSH.S text
		#emit PUSH.C 144
		#emit PUSH.C str
		#emit LOAD.S.pri 8
		#emit ADD.C 4
		#emit PUSH.pri
		#emit SYSREQ.C format
		#emit LCTRL 5
		#emit SCTRL 4

		SendClientMessageToAll(color, str);

		#emit RETN
	}
	return 1;
}
