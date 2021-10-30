fs = 200000;
bw = 1/3;

fMin = 20;
fMax = 16000;

octs = log2(fMax/fMin);
bmax = ceil(octs/bw);

fc = fMin*2.^( (0:bmax) * bw ); % centre frequencies
fl = fc*2^(-bw/2); % lower cutoffs
fu = fc*2^(+bw/2); % upper cutoffs

numBands = length(fc);

b = cell(numBands,1);
a = cell(numBands,1);

figure
for nn = 1:length(fc)

    [b{nn},a{nn}] = butter(2, [fl(nn) fu(nn)]/(fs/2), 'bandpass');
    [h,f]=freqz(b{nn},a{nn},1024,fs);

    hold on;
    plot(f, 20*log10(abs(h)) );

end
set(gca, 'XScale', 'log')
xlim([20 20000])
ylim([-50 0])