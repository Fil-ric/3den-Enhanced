/*
	Author: Revo

	Description:
	Used by the Enh_TexturFinder GUI. Searches the config file for useable textures.

	Parameter(s):
	-

	Returns:
	BOOLEAN: true / false
*/

//Only add things which end with eighter jpg or paa
#define IS_JPG (".jpg" in (_string select [count _string-4]))
#define IS_PAA (".paa" in (_string select [count _string-4]))

//Update progress bar (Should only run if searching is in progress, but also runs if searching was finished, optimize?)
[] spawn Enh_fnc_textureFinder_updateProgressbar;

if !(isNil "Enh_TextureFinder_TexturesFound") exitWith {false};

//Check if search is already running
if !(isNil "Enh_FindTexture_SearchRunning") exitWith {[localize "STR_ENH_searchState_pleaseWait",1] call BIS_fnc_3DENNotification; false};

disableSerialization;

_display = findDisplay 140000;
_ctrlProg = _display displayCtrl 1001;
_ctrlProgText = _display displayCtrl 1002;

Enh_TextureFinder_TexturesFound = [];
Enh_TextureFinder_ClassesFound = 0;
Enh_TextureFinder_ClassesSearched = 0;

//Scan configFile for all classes

private _fnc_searchConfig = 
{
    params [["_depth", 1], ["_class", configFile]];
     
    if (_depth <= 0) exitWith {[]};
    _depth = _depth - 1;
    private _array = [];
  
    {  
        _array pushBack _x;
        Enh_TextureFinder_ClassesFound = Enh_TextureFinder_ClassesFound + 1;
        _array append ([_depth, _x] call _fnc_searchConfig);
    } forEach ("true" configClasses _class);
  
   _array
};
  
private _classes = [13] call _fnc_searchConfig;

//Check configProperties of every class for textures
private _string = "";
{
	Enh_TextureFinder_ClassesSearched = Enh_TextureFinder_ClassesSearched + 1;
	{
		_string = getText _x;
		if (IS_PAA || IS_JPG) then
		{
			Enh_TextureFinder_TexturesFound pushBackUnique _string;
		};
	} forEach configProperties [_x, "isText _x"];
} forEach _classes;

Enh_FindTexture_SearchRunning = nil;

true