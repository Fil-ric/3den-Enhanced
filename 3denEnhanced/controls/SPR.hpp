class ENH_SPR: Title
{
	attributeLoad = "[_this,_value] call ENH_fnc_SPR_onAttributeLoad";
	attributeSave = "_this call ENH_fnc_SPR_onAttributeSave";
	h = 10.5 * SIZE_M * GRID_H + 30 * pixelH;
	class Controls: Controls
	{
		class DescriptionGroup: ctrlControlsGroup
		{
			x = 5 * GRID_W;
			y = 0.5 * SIZE_M * GRID_H;
			h = 5 * SIZE_M * GRID_H;
			w = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W) * GRID_W;
			class Controls
			{
				class DescriptionDeco: ctrlStatic
				{
					w = 5 * pixelW;
					h = SIZE_M * GRID_H;
					colorBackground[] = {1,1,1,0.05};
				};
				class DescriptionHeader: ctrlStatic
				{
					text = $STR_ENH_DESCRIPTION;
					x = 7 * pixelW;
					w = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - 4) * GRID_W - 7 * pixelW;
					h = SIZE_M * GRID_H;
					colorText[] = {1,1,1,0.4};
					colorBackground[] = {1,1,1,0.05};
					colorShadow[] = {0,0,0,0};
				};
				class Description: ctrlStructuredText
				{
					text = $STR_ENH_SPR_DESCRIPTION;
					x = 7 * pixelW;
					y = SIZE_M * GRID_H;
					w = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - 4) * GRID_W - 7 * pixelW;
					h = 4 * SIZE_M * GRID_H;
					colorText[] = {1,1,1,0.4};
					colorBackground[] = {1,1,1,0};
					shadow = 0;
					class Attributes
					{
						align = "left";
						color = "#999999";
						colorLink = "";
						font = "RobotoCondensedLight";
						size = 1;
					};
				};
			};
		};
		class RulesetTitle: Title
		{
			text = $STR_3DEN_MULTIPLAYER_ATTRIBUTE_RESPAWNTEMPLATES_DISPLAYNAME;
			y = 5.5 * SIZE_M * GRID_H + 5 * pixelH;
		};
		class Ruleset: ctrlCombo
		{
			idc = 100;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 5.5 * SIZE_M * GRID_H + 5 * pixelH;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = SIZE_M * GRID_H;
		};
		class RespawnTimeTitle: Title
		{
			y = 6.5 * SIZE_M * GRID_H + 10 * pixelH;
			text = $STR_3DEN_MULTIPLAYER_ATTRIBUTE_RESPAWNDELAY_DISPLAYNAME;
			tooltip = $STR_3DEN_MULTIPLAYER_ATTRIBUTE_RESPAWNDELAY_TOOLTIP
		};
		class RespawnTimeValue: ctrlXSliderH
		{
			idc = 101;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 6.5 * SIZE_M * GRID_H + 10 * pixelH;
			w = (ATTRIBUTE_CONTENT_W - EDIT_W) * GRID_W;
			h = SIZE_M * GRID_H;
		 	sliderPosition = 20;
			sliderRange[] = {0,360};
			sliderStep = 1;
		};
		class TimeEdit: ctrlEdit
		{
			idc = 102;
			x = (ATTRIBUTE_TITLE_W + ATTRIBUTE_CONTENT_W - EDIT_W) * GRID_W;
			y = 6.5 * SIZE_M * GRID_H + 10 * pixelH;
			w = EDIT_W * GRID_W;
			h = SIZE_M * GRID_H;
		};	
		class CanDieTitle: Title
		{
			text = $STR_ENH_SPR_CANDIE_DISPLAYNAME;
			tooltip = $STR_ENH_SPR_CANDIE_TOOLTIP;
			y = 7.5 * SIZE_M * GRID_H + 15 * pixelH;
		};
		class CanDie: ctrlCheckbox
		{
			idc = 103;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 7.5 * SIZE_M * GRID_H + 15 * pixelH;
			w = 5 * GRID_W;
			h = SIZE_M * GRID_H;
		};
		class RestoreLoadoutTitle: Title
		{
			text = $STR_ENH_SAVELOADOUT_DISPLAYNAME;
			tooltip = $STR_ENH_SAVELOADOUT_TOOLTIP;
			y = 8.5 * SIZE_M * GRID_H + 20 * pixelH;
		};
		class RestoreLoadout: ctrlCheckbox
		{
			idc = 104;
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 8.5 * SIZE_M * GRID_H + 20 * pixelH;
			w = 5 * GRID_W;
			h = SIZE_M * GRID_H;
		};
		class Reset: ctrlButton
		{
			x = ATTRIBUTE_TITLE_W * GRID_W;
			y = 9.5 * SIZE_M * GRID_H + 25 * pixelH;
			w = ATTRIBUTE_CONTENT_W * GRID_W;
			h = SIZE_M * GRID_H;
			onButtonDown  = "_this call ENH_fnc_SPR_onButtonDown";
			text = $STR_ENH_RESETANDDISABLE;
		};
	};
};