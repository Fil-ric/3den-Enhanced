class ENH_DoStop
{
  displayName = $STR_ENH_DOSTOP_DISPLAYNAME;
  tooltip = $STR_ENH_DOSTOP_TOOLTIP;
  control = "Checkbox";
  property = "ENH_doStop";
  expression = "if (!is3DEN && _value && !isMultiplayer) then {doStop _this}";
  condition = "objectBrain + objectVehicle";
  defaultValue = "false";
};