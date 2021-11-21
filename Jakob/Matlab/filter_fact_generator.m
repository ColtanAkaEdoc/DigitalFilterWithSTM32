%-------------------------------------
% FILTER-FACT-GENERATOR
%-------------------------------------

% Calculate bands
%*************************************
fs = 48000;     % [Hz] desired sampling rate of device
fmin = 20;      % [Hz] minimal desired low-end
fmax = 20480;   % [Hz] minimal desired high-end

oct_bw_ratio = 1/3; % [1] desired octave-split

n_octs = log2(fmax/fmin);               % [1] number of octaves from fmin to fmax
n_bands = ceil(n_octs/oct_bw_ratio);    % [1] number of octave divisions from fmin to fmax
n_coeffs_p_section = 6;
n_sections = 3;

fc = fmin*2.^((0:n_bands) * oct_bw_ratio);  % [Hz] center frequencies. 
                                            % "(0:n_bands)" means to iterate from 0 to n_bands 
                                            % and store result in vector
fl = fc*2^(-oct_bw_ratio/2);                % lower cutoffs @ -3dB (required by filter-designer)
fu = fc*2^(+oct_bw_ratio/2);                % upper cutoffs @ -3dB (required by filter-designer)


% Create C-header file
%*************************************
h_name = "_COEFFICIENTS_H_";
header =    "#ifndef " + h_name + newline + "#define " + h_name + newline + newline + ...
            '// info:' + newline + '// number of bands: ' + string(n_bands) + newline + ...
            '// contains coeffs for 30 sets of 3-section biquad 1/3rd octave filters' + newline;

path = './coefficients.h';
fileID = fopen(path ,'w');
fprintf(fileID, header);
fclose(fileID);

fileID = fopen(path ,'a');

for i_b = 0:n_bands
    
    index = 1 + n_bands - i_b;
    filter = gen_iir_osix_bp(fl(index), fu(index), fs);
    
    name = append('float iir_', string(index), '[] = {', newline, ...
                  '    // fs = ', string(fs), ...
                  ', fl = ', string(fl(index)), ...
                  ', fu = ', string(fu(index)) ...
                  );
    fprintf(fileID, name);
    fprintf(fileID, newline);
    % The coefficients are stored in the array pCoeffs in the following order:
    % {b10, b11, b12, a11, a12, b20, b21, b22, a21, a22, ...}
    % where b1x and a1x are the coefficients for the first stage, 
    % b2x and a2x are the coefficients for the second stage, and so on. 
    % The pCoeffs array contains a total of 5*numStages values.
    % ~~~ from ARM CMSIS DSP library wiki (https://www.keil.com/pack/doc/CMSIS/DSP/html/group__BiquadCascadeDF1.html#gad0b680d1c529d941e939d265b3c6ae59)
    for i_s = 1:n_sections
       for i_c = 1:n_coeffs_p_section
           if i_c == 4 % the 4th coefficient (always 1) is not accepted
               continue;
           end    
           value = string(filter.sosMatrix(i_s, i_c));
           line = append('    ', value, ',');
           fprintf(fileID, line);
       end
       fprintf(fileID, newline);
    end
    fprintf(fileID, '};');
    fprintf(fileID, newline);
    
    if ((mod((i_b + 1), n_sections)-1) == 0) && ((i_b + 1) ~= 1) % treats the 1st 4 filters as one unit and after that sets of 3 filters
        fs = fs/2; % for decimator
    end    
end

% closing statement
fprintf(fileID, '#endif // coefficients.h');
fclose(fileID);




