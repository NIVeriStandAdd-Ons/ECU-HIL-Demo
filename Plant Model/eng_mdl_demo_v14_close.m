function proj_close()
% This file is executed when the project model file is closed.
% This file should not need to be modified for most projects.
if isempty(bdroot) || strcmp(bdroot, 'simulink'), return; end


% This removes the directory containing the model and all subdirectories from the MATLAB path.
prj = lower(fileparts(which(bdroot)));
r = path;
while (~isempty(r))
    [t,r] = strtok(r, pathsep);
    if strcmp(lower(t), prj)  || ~isempty(strfind(lower(t), [prj filesep]) == 1)
        rmpath(lower(t));
    end
end


