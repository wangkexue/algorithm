function captureFrame
%{
%% Construct a VideoReader object for the example movie file xylophone.mp4 and view its properties:

xyloObj = VideoReader('person01_boxing_d1_uncomp.avi','Tag','My reader object');
get(xyloObj)
%}
cd /Users/wangkexue/Downloads/tracklet_descriptor_code/data/kth/frames
%dirpath = {'boxing', 'handclapping', 'handwaving', 'jogging', 'running', 'walking'};
dirpath = {'jogging', 'running', 'walking'};
data_size = 25;
for i = 1:size(dirpath, 2)
    disp(dirpath{i})
    eval(['cd ', dirpath{i}]);
    for j = 1:25
        disp(j);
        for n = 1:4
            video_name = strcat('person', sprintf('%02d', j), '_', dirpath{i}, '_d', num2str(n), '_uncomp.avi');
            if ~exist(video_name, 'file')
                continue;
            end
            frame_dir = strsplit(video_name, '.');
            mkdir(frame_dir{1});
            %% Read and play back the movie file xylophone.mp4:

            xyloObj = VideoReader(video_name);

            nFrames = xyloObj.NumberOfFrames;
            vidHeight = xyloObj.Height;
            vidWidth = xyloObj.Width;

            % Preallocate movie structure.
            mov(1:nFrames) = ...
                struct('cdata', zeros(vidHeight, vidWidth, 3, 'uint8'),...
                       'colormap', []);

            % Read one frame at a time.
            frame_dir_d = frame_dir{1};
            parfor k = 1 : nFrames
                file_name = strcat(frame_dir_d, '/frame_',sprintf('%03d', k),'.png');
                if exist(file_name, 'file')
                    continue;
                end
                mov(k).cdata = read(xyloObj, k);
                imwrite(mov(k).cdata, file_name);
            end

            % Size a figure based on the video's width and height.
            %hf = figure;
            %set(hf, 'position', [150 150 vidWidth vidHeight])

            % Play back the movie once at the video's frame rate.
            %movie(hf, mov, 1, xyloObj.FrameRate);
        end
    end
cd ..
end
