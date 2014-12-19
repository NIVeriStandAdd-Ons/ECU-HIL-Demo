function res = notex(s)

res = [];

for i=1:length(s)
    switch  s(i)
        case {'_'}
            res = [res '\' s(i)];
        otherwise
            res = [res s(i)];
    end
end
            