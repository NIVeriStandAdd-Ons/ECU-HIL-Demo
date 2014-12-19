% This file is executed when the project model file is opened, and before every update (^D).
if isempty(bdroot) || strcmp(bdroot, 'simulink'), return; end


% This adds the current directory to the MATLAB path,
% along with directories for Images, CAN, and Simulink libraries.
% Add to this list as your project grows.
addpath(fileparts(which(bdroot)));
addpath(genpath([fileparts(which(bdroot)) filesep 'Images']));
addpath(genpath([fileparts(which(bdroot)) filesep 'Libraries']));


evalin('base', ['load ws'], '');






